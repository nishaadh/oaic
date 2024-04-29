Running the DRL-SS xApp
=======================

Under the oaic directory, run the following commands

.. code-block:: bash

    git clone https://github.com/nishaadh/drl-ss.git

Before we deploy xApp, we need to configure the host files.

====================================
xApp Deployment - General Guidelines
====================================

Pre-requisites
==============

Hosting Files on a Web Server 
-----------------------------

The xApp descriptor files (config.json) must be hosted on a webserver when we use the **xapp-onboarder** to deploy xApps. To host these files we use Nginx to create a web server.

.. _createnginx:

Configuring the Nginx Web server
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

First, we need to install Nginx and check if it is in ``active (running)``  state. 

.. code-block:: rst

	sudo apt-get install nginx
	sudo systemctl status nginx

Unlink the default Configuration file and check if it is unlinked

.. code-block:: rst

	cd /etc/nginx/sites-enabled
	sudo unlink default
	cd ../

Now we create some directories which can be accessed by the server and where the config files can be hosted

.. code-block:: rst

	cd ../../var/www
	sudo mkdir xApp_config.local
	cd xApp_config.local/
	sudo mkdir config_files

Create a Custom Configuration File and define file locations

.. code-block:: rst
	
	cd ../../../etc/nginx/conf.d
	sudo vim xApp_config.local.conf

Paste the following content in the *conf* file.

.. code-block:: rst  

	server {
	    listen 5010 default_server;
	    server_name xApp_config.local;
	    location /config_files/ {

		root /var/www/xApp_config.local/;
	    }

	}


Save the configuration file and check if there are any errors in the configuration file.

.. code-block:: rst

	sudo nginx -t

.. _hostxAppdescriptor:

Hosting the config Files
~~~~~~~~~~~~~~~~~~~~~~~~

Copy the xApp config file to this directory. Reload Nginx once this has been done

.. code-block:: rst
	
	sudo cp <path_to_config_file>/config-file.json /var/www/xApp_config.local/config_files/
	sudo systemctl reload nginx

Now, you can check if the config file can be accessed from the newly created server. Place all files you want to host in the ``config_files`` directory

.. code-block:: rst

	curl http://<machine_ip_addr>:5010/config_files/config-file.json

.. tip::

	* Place all files you want to host in the ``config_files`` directory.
	* Make sure all files have a unique name


Creating xApp Docker Image
==========================

.. code-block:: bash

    cd ~/oaic/drl-ss  
    sudo docker build . -t xApp-registry.local:5008/drl-ss:0.1.0

Paste the following in the ``drl-ss-onboard.url`` file. Substitue the ``<machine_ip_addr>`` with the IP address of your machine. You can find this out through ``ifconfig``.

.. code-block:: bash

    {"config-file.json_url":"http://<machine_ip_addr>:5010/config_files/config-file.json"}
    
Make sure you have the ue information added to the srsltwconfig files

.. code-block:: bash

    sudo -i
    vim .config/srslte/user_db.csv

Paste this into the user_db.csv file

.. code-block:: bash

    ue2,xor,001010123456780,00112233445566778899aabbccddeeff,opc,63bfa50ee6523365ff14c1f45f88737d,8000,000000001590,7,dynamic
    ue3,xor,001010123456781,00112233445566778899aabbccddeeff,opc,63bfa50ee6523365ff14c1f45f88737d,8002,000000001488,7,dynamic
    ue1,xor,001010123456789,00112233445566778899aabbccddeeff,opc,63bfa50ee6523365ff14c1f45f88737d,9001,000000001656,7,dynamic
    

Deploying xApp using a script with ZMQ
--------------------------------------

The script depends on the assumption that iperf3 and gnuradio packages and screen command are installed and functioning.

.. code-block:: bash

    sudo ./setup_env_drl.sh


