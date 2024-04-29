.. _gettingstarted:

Getting Started
===============

Introduction
------------

OAIC is an open-source effort led by a consortium of academic institutions to provide fully open-source software architecture, library, and toolset that encompass both the AI controllers (OAIC-C) as well as an AI testing framework (OAIC-T). This project will develop a software infrastructure that spurs research and development on AI-enabled cellular radio networks. We leverage existing open-source 5G software efforts to create a framework which integrates AI controllers into 5G processing blocks and extends the scope of the Open Radio Access Network (O-RAN) framework, the industry standard for future RANs.


To use Open AI Cellular, first clone the `oaic <https://github.com/nishaadh/oaic.git>`_ repository:

.. code-block:: rst

   git clone https://github.com/nishaadh/oaic.git

oaic is the root directory for all purposes. Different components of OAIC like the Near-real time RIC, srsRAN and xApps are linked as submodules in this directory. Performing an update of the submodules will provide all the files required to run OAIC.

Check out the latest version of every dependent submodule within the “oaic” repository.

.. code-block:: rst

    cd oaic 


==================================
Hardware and Software Requirements
==================================

Hardware Requirements:
======================

Integrated O-RAN Solution
-------------------------

O-RAN system:
~~~~~~~~~~~~~

* 1 computer with 10 Gbps NIC
* 1 SDR (X or N for 5G)

Each UE:
~~~~~~~~

* 1 computer with 10 Gbps NIC
* 1 SDR (X or N for 5G) 
        - e.g. X310 or N310 USRP

Software Requirements: 
=======================

OS and Packages
---------------

Operating System: Ubuntu 20.04 
Major Packages: Docker,Kubernetes, Helm

===========================================
O-RAN Near-Real Time RIC Installation Guide
===========================================

Pre-requisites
==============

System Requirements
-------------------

* OS: `Ubuntu 20.04 LTS (Bionic Beaver) <https://en.wikipedia.org/wiki/Ubuntu_version_history#:~:text=Table%20of%20versions%20%20%20%20Version%20,Future%20release%3A%202027-04-21%20%2011%20more%20rows%20>`_
* CPU(s): 2-4 vCPUs
* RAM: 6-16 GB
* Storage: 20-160 GB

O-RAN Near-Real Time RIC Software Architecture
----------------------------------------------

.. image:: near_rt_ric_cluster.jpg
   :width: 60%
   :alt: Near Real-time RIC Cluster


Near-Real Time RIC Installation Procedure
=========================================


Step 1: Install and configure an Ubuntu Host Machine/ Virtual Machine (VM)
--------------------------------------------------------------------------

The near-real time RIC can be run on a host machine or a VM as per your preference (A VM is recommended if your system is powerful enough to support multiple VMs).

In this instruction set we assume the VM/Linux host system is already configured with the specified system requirements. If you need help with VM installation on Windows 10, `check out this video <https://www.youtube.com/watch?v=x5MhydijWmc>`_.

This completes step 1.


Step 2: Install Kubernetes, Docker, and Helm
--------------------------------------------

.. note:: 

   Before you begin, please clone the parent `oaic <https://github.com/openaicellular/oaic>`_ directory as outlined in :ref:`Getting Started <gettingstarted>`.


Near-Real Time RIC
~~~~~~~~~~~~~~~~~~

The installation of Near Realtime RAN Intelligent Controller is spread onto 
two separate Kubernetes clusters.
The first cluster is used for deploying the Near Realtime RIC (platform and 
applications), and the other is for deploying other auxiliary functions.
They are referred to as **RIC cluster** and **AUX cluster** respectively [1]_.

The **RIC cluster** consists of 3 major Kubernetes Systems.
Each of them is separated by their specified namespaces (kube-system ns, 
ricinfra ns, ricplt ns):

**Kube-system ns:** The underlying Kubernetes application which provides the basic 
framework for deployment and maintenance of pods.


RIC Kubernetes Cluster Installation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


The ``RIC-Deployment`` directory contains the deployment scripts and pre generated helm charts for each of the RIC components. This repository also contains some “demo” scripts which can be run after complete installation.

.. code-block:: bash

    cd RIC-Deployment/tools/k8s/bin
    

This directory contains tools for generating a simple script that can help us set up a one-node Kubernetes cluster (OSC also supports a 3 node Master slave Kubernetes configuration, but we do not cover that here).

The scripts automatically read in parameters (version specifications, setting up private containers/registries) from the following files:

  - ``k8s/etc/infra.rc``: specifies the docker host, Kubernetes, and Kubernetes CNI (Cluster Networking Interfaces) versions. If left unspecified, the default version is installed.
  - ``k8s/etc/env.rc``: Normally no change needed for this file. Can specify special/custom Kubernetes Cluster components, such as running private Docker registry with self-signed certificates, or hostnames that can be only resolved via private /etc/hosts entries.
  - ``etc/openstack.rc``: (Relevant only for Open Stack VMs) If the Kubernetes cluster is deployed on Open Stack VMs, this file specifies parameters for accessing the APIs of the Open Stack installation.

For a simple installation there is no need to modify any of the above files. The files give flexibility to define our own custom Kubernetes environment if we ever need to.
Run the script which will generate the Kubernetes stack install script. Executing the below command will output a shell script called ``k8s-1node-cloud-init-k_1_16-h_2_17-d_cur.sh``. The file name indicates that we are installing Kubernetes v1.16 (k_1_16), Helm v2.17 (h_2_17) and the latest version of docker (d_cur).

.. code-block:: bash

    ./gen-cloud-init.sh

Executing the generated script ``k8s-1node-cloud-init-k_1_16-h_2_17-d_cur.sh`` will install Kubernetes, Docker and Helm with version specified in the k8s/etc/infra.c. This also installs some pods which help cluster creation, service creation and internetworking between services. Running this script will replace any existing installation of Docker host, Kubernetes, and Helm on the VM. The script will reboot the machine upon successful completion. This will take some time (approx. 15-20 mins).

.. code-block:: bash

    sudo ./k8s-1node-cloud-init-k_1_16-h_2_17-d_cur.sh


Once the machine is back up, check if all the pods in the newly installed Kubernetes Cluster are in “Running” state using,

.. code-block:: bash

    sudo kubectl get pods -A  
    

There should be a total of **9** pods up and running in the cluster.

These pods serve as the Kubernetes Framework which will be helpful in deploying the RIC platform.
We briefly detail each of the pods’ functionality (Most of which help in networking between Kubernetes nodes) [].

  * ``CoreDNS``: DNS server that serves as the Kubernetes cluster DNS. This is a replacement for the default kube-dns service.
  * ``Flannel``: Flannel is a basic overlay network that works by assigning a
    range of subnet addresses (usually IPv4).
    To facilitate inter-container connectivity across nodes, flannel is used. 
    Flannel does not control how containers are networked to the host, only 
    how the traffic is transported between hosts. Flannel uses etcd to 
    maintain a mapping between allocated subnets and real host IP addresses. 
    For example, this is very useful when the RAN is trying to communicate 
    with the RIC since they are both different/separate nodes.
  * ``Etcd server``: Consistent and highly available key value store (similar to a dictionary or a map) used as
    Kubernetes' backing store for all cluster data.
    Example : Used by Flannel to register its container’s IP. etcd server 
    stores a key-value mapping of each container with its IP.
  * ``Kube-APIserver``: A control plane module that exposes the Kubernetes API. 
    The API server is the front end for the Kubernetes control plane. The 
    Kubernetes API server validates and configures data for the api objects 
    which include pods, services, replication controllers, and others. For 
    example, it uses etcd server as a service to get the IP mappings and 
    assign service IPs accordingly.
  * ``Kube-proxy``: Creates iptables rules and allocates static endpoints and 
    load balancing. Basically, this means, in case the node goes down or the 
    pod restarts it will get a new local IP, but the service IP created by 
    kubernetes will remain the same enabling kubernetes to route traffic to 
    correct set of pods. See [], [], [] for more details on networking in 
    docker and Kubernetes.
  * ``Kube-scheduler``: Control plane component that watches for newly created 
    Pods with no assigned node and selects a node for them to run on. The 
    scheduler determines which Nodes are valid placements for each Pod in the 
    scheduling queue according to constraints and available resources. 
    Constraints include collective resource requirements, 
    hardware/software/policy constraints, inter-workload interference, and 
    deadlines.
  * ``Kube-controller-manager``: Control plane component that runs controller 
    processes. Some examples of controller processes include node controller 
    (Responsible for noticing and responding when nodes go down), job 
    controller (Watches for Job objects that represent one-off tasks, then 
    creates Pods to run those tasks to completion) etc.
  * ``Tiller-deploy``: the server portion of Helm, typically runs inside the 
    Kubernetes cluster. Tiller is the service that communicates with the 
    Kubernetes API to manage our RIC components’ Helm packages. Discontinued 
    since Helm v3 since it was seen as a security risk. But in our 
    deployments, we are still using Helm v2, so tiller is essential.

Onetime setup for Influxdb
~~~~~~~~~~~~~~~~~~~~~~~~~~

Once Kubernetes setup is done, we have to create PersistentVolume through the storage class for the influxdb database.
The following one time process should be followed before deploying the influxdb in ricplt namespace.

    **Persistent Volume**:

First we need to check if the "ricinfra" namespace exists.

.. code-block:: rst

    sudo kubectl get ns ricinfra

If the namespace doesn’t exist, then create it using:

.. code-block:: bash

    sudo kubectl create ns ricinfra

The next three commands installs the nfs-common package for kubernetes through helm in the "ricinfra" namespace and for the system

.. code-block:: bash

    sudo helm install stable/nfs-server-provisioner --namespace ricinfra --name nfs-release-1
    sudo kubectl patch storageclass nfs -p '{"metadata": {"annotations":{"storageclass.kubernetes.io/is-default-class":"true"}}}'
    sudo apt install nfs-common
    
.. tip::

   When the RIC platform is undeployed, the ``ricinfra`` namespace will also be removed. So, you will need to run the one-time setup procedure again when re-deploying    the RIC.

NFS-common basically allows file sharing between systems residing on a local area network.


Step 3: Build Modified E2 docker Image
--------------------------------------

Pre-requisites
~~~~~~~~~~~~~~	

Local docker registry to host docker images. You can create one using, (You will need "super user" permissions)

.. code-block:: bash

    sudo docker run -d -p 5001:5000 --restart=always --name ric registry:2
 
Now you can either push or pull images using,
``docker push localhost:5001/<image_name>:<image_tag>``
or ``docker pull localhost:5001/<image_name>:<image_tag>``
 

Creating Docker image
~~~~~~~~~~~~~~~~~~~~~

Navigate to ``ric-plt-e2`` directory.

.. code-block:: bash
   
   cd ../../../..
   cd ric-plt-e2 

The code in this repo needs to be packaged as a docker container. We make use of the existing Dockerfile in RIC-E2-TERMINATION to do this. Execute the following commands in the given order 

.. code-block:: bash

    cd RIC-E2-TERMINATION
    sudo docker build -f Dockerfile -t localhost:5001/ric-plt-e2:5.5.0 .
    sudo docker push localhost:5001/ric-plt-e2:5.5.0
    cd ../../

This image can be used when deploying the near-real time RIC Kubernetes Cluster in the next step.

      
When the RIC platform is deployed, you will have the modified E2 Termination running on the Kubernetes cluster. The pod will be called `deployment-ricplt-e2term-alpha` and 3 services related to E2 Termination will be created:

  - ``service-ricplt-e2term-prometheus-alpha`` : Communicates with the *VES-prometheus Adapter (VESPA)* pod to send data to the SMO.
  - ``service-ricplt-e2term-rmr-alpha`` : RMR service that manages exchange of messages between E2 Termination other components in the near-real time RIC.
  - ``service-ricplt-e2term-sctp-alpha`` : Accepts SCTP connections from RAN and exchanges E2 messages with the RAN. Note that this service is configured as a *NodePort* (accepts connections external to the cluster) while the other two are configured as *ClusterIP* (Networking only within the cluster). 

Commands related to E2 Termination
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  - View E2 Termination logs : ``kubectl logs -f -n ricplt -l app=ricplt-e2term-alpha``
  - View E2 Manager Logs : ``kubectl logs -f -n ricplt -l app=ricplt-e2mgr``
  - Get the IP *service-ricplt-e2term-sctp-alpha* : ``kubectl get svc -n ricplt --field-selector metadata.name=service-ricplt-e2term-sctp-alpha -o jsonpath='{.items[0].spec.clusterIP}'``


Step 4: Deploy the near-Real Time RIC
-------------------------------------

Once the Kubernetes clusters are deployed, it is now time for us to deploy the near-real time RIC cluster.

.. code-block:: bash

    cd RIC-Deployment/bin
    sudo ./deploy-ric-platform -f ../RECIPE_EXAMPLE/PLATFORM/example_recipe_oran_e_release_modified_e2.yaml
    
This command deploys the near-real time RIC according to the RECIPE stored in ``RIC-Deployment/RECIPE_EXAMPLE/PLATFORM/`` directory. A Recipe is an important concept for Near Realtime RIC deployment. Each deployment group has its own recipe. Recipe provides a customized specification for the components of a deployment group for a specific deployment site. The ``RECIPE_EXAMPLE`` directory contains the example recipes for the three deployment groups (bronze, cherry, dawn, e-release). The benefit of using *recipe files* is that changing over from one release to another is seamless requiring just the execution of a single script without having to perform “Step 2” all over again.

An example of changing the recipe file to suit our requirements is shown below. Instead of using the E2 Termination image provided by the O-RAN SC, we make use of the modified E2 Termination image created in the previous image. To do this, we modify the ``e2term`` section in the recipe file present in ``RIC-Deployment/RECIPE_EXAMPLE/PLATFORM`` to point to the new image,


.. code-block:: rst
   :emphasize-lines: 4,5,6

    e2term:
      alpha:
        image:
          registry: "localhost:5001"
          name: ric-plt-e2
          tag: 5.5.0
        privilegedmode: false
        hostnetworkmode: false
        env:
          print: "1"
          messagecollectorfile: "/data/outgoing/"
        dataVolSize: 100Mi
        storageClassName: local-storage
        pizpub:
          enabled: false`


Structure of the "RIC-Deployment" Directory
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The scripts in the ./bin directory are one-click RIC deployment/undeployment scripts and will call the deployment/undeployment
scripts in the corresponding submodule directory respectively. In each of the submodule directories, ./bin contains
the binary and script files and ./helm contains the helm charts. For the rest of the non-submodule directories please
refer to the README.md files in them for more details.

=======================================
srsLTE with E2 Agent Installation Guide
=======================================

.. note:: 

   Before you begin, please clone the parent `oaic <https://github.com/openaicellular/oaic>`_ directory as outlined in :ref:`Getting Started <gettingstarted>`.

srsRAN is a 4G/5G software radio suite developed by `SRS <http://www.srs.io)>`_. This is a modified version of `srsRAN 21.10 <https://github.com/srsran/srsRAN>`_ and `POWDER's E2 agent enabled srsLTE <https://gitlab.flux.utah.edu/powderrenewpublic/srslte-ric>`_. 

See the `srsRAN project pages <https://www.srsran.com>`_ for information, guides and project news.

The srsRAN suite includes:
  - srsUE - a full-stack SDR 4G/5G-NSA UE application (5G-SA coming soon)
  - srsENB - a full-stack SDR 4G/5G-NSA eNodeB application (5G-SA coming soon)
  - srsEPC - a light-weight 4G core network implementation with MME, HSS and S/P-GW

For application features, build instructions and user guides see the `srsRAN documentation <https://docs.srsran.com>`_.


For license details, see LICENSE file - *Needs to be modified.*

Pre-requisites
--------------

.. admonition:: TODO

   Create a system specification table for different cellular configurations

- System Requirements - 4 core CPU (3 - 5 GHz)
- Operating system - Ubuntu 20.04
- E2 Agent Integration - E2 Bindings, asn1c Compiler, O-RAN Specification documents(optional)
- Simulated 1 UE 1 eNB/gNB setup - ZeroMQ libraries, Single Host machine/VM
- USRP frontend - UHD version 4.1, At least two host machines/VMs
- Multiple simulated UE and eNB/gNB support : GNU Radio companion 3.9

Dependencies Installation
~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash
    
    sudo apt-get install build-essential cmake libfftw3-dev libmbedtls-dev libboost-program-options-dev libconfig++-dev libsctp-dev libtool autoconf


ZeroMQ Installation
-------------------

srsRAN software suite includes virtual radios which uses the ZeroMQ networking library to transfer radio samples between applications. This approach is very useful for development, testing, debugging, CI/CD or for teaching and demonstrating. Natively, ZeroMQ with srsRAN supports only one eNB/gNB and one UE configuration but it can be extended to support multiple UEs using GNU Radio. Have a look at the tutorial to do this :ref:`here <multiple_ue>`.


Getting ZeroMQ development Libraries
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`ZeroMQ Installation Instructions <https://docs.srsran.com/en/latest/app_notes/source/zeromq/source/index.html>`_

**Package Installation**

.. code-block:: bash

    sudo apt-get install libzmq3-dev



.. _uhd_installation:

UHD 4.1 Installation
-------------------- 

.. warning::
   Make sure you don't have UHD already installed in your system. The system might not work if there are multiple versions of UHD

`Ettus UHD Binary Installation Manual`_

.. _Ettus UHD Binary Installation Manual: https://files.ettus.com/manual/page_install.html

Using package manager
~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    sudo add-apt-repository ppa:ettusresearch/uhd
    sudo apt-get update
    sudo apt-get install libuhd-dev libuhd4.1.0 uhd-host



asn1c Compiler Installation
---------------------------

We will be using the modified asn1c compiler (for RAN and CN) that is hosted by Open Air Interface (OAI)

.. code-block:: bash

    cd ../..
    sudo apt install libtool autoconf
    git clone https://gitlab.eurecom.fr/oai/asn1c.git
    cd asn1c
    git checkout velichkov_s1ap_plus_option_group
    autoreconf -iv
    ./configure
    make -j`nproc`
    sudo make install
    sudo ldconfig
    cd ..

srsRAN with E2 agent Installation
---------------------------------
 
Installation from Source
~~~~~~~~~~~~~~~~~~~~~~~~

.. warning::
   This step will have to be performed again if any of the above librarires change. For example, if UHD is updated, you will have to re-build srsRAN to make use of the updated library.

.. code-block:: bash

    git clone https://github.com/openaicellular/srslte-e2
    cd srslte-e2

.. code-block:: bash
    
    rm -rf build
    mkdir build
    export SRS=`realpath .`
    cd build
    cmake ../ -DCMAKE_BUILD_TYPE=RelWithDebInfo \
        -DRIC_GENERATED_E2AP_BINDING_DIR=${SRS}/e2_bindings/E2AP-v01.01 \
        -DRIC_GENERATED_E2SM_KPM_BINDING_DIR=${SRS}/e2_bindings/E2SM-KPM \
        -DRIC_GENERATED_E2SM_GNB_NRT_BINDING_DIR=${SRS}/e2_bindings/E2SM-GNB-NRT
    make -j`nproc`
    make test
    sudo make install
    sudo ldconfig
    sudo srslte_install_configs.sh user --force
    cd ../../
    
We can now clone the repositories we will need to run build the xapp and onboard it as well as run multiple UEs.

.. warning::
    Make sure you open a new terminal before you run these following commands. This prevents you from downloading anything under the root directory.

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
    
Running the DRL-SS xApp
=======================

Deploying xApp using a script with ZMQ
--------------------------------------

The script depends on the assumption that iperf3 and gnuradio packages and screen command are installed and functioning.

.. code-block:: bash

    sudo ./setup_env.sh

You could also manually deploy the xApp by starting the network. The instructions to that are below:

Deploying xApp without script with ZMQ
--------------------------------------

Starting the network with ZMQ 
-----------------------------

.. warning::

    If you already have DRL-SS xApp deployed on your system, you need to restart the pod using the command below before running the rest of the commands. If you are freshly deploying the xApp, you can skip this step.

.. code-block:: bash

    sudo kubectl -n ricxapp rollout restart deployment ricxapp-drl-ss

Terminal 1: Start the Core Network/Add Ues to Network Namespace

.. code-block:: bash

    sudo ip netns add ue1
    sudo ip netns add ue2
    sudo ip netns list    
    sudo srsepc 

Terminal 2: Set up Environment Variables and Base Station

.. code-block:: bash

    export E2NODE_IP=`hostname  -I | cut -f1 -d' '`
    export E2NODE_PORT=5006
    export E2TERM_IP=`sudo kubectl get svc -n ricplt --field-selector metadata.name=service-ricplt-e2term-sctp-alpha -o jsonpath='{.items[0].spec.clusterIP}'`
    
.. code-block:: bash
       
    sudo srsenb --enb.n_prb=100 --enb.name=enb1 --enb.enb_id=0x19B --rf.device_name=zmq 		--rf.device_args="fail_on_disconnect=true,tx_port=tcp://*:2000,rx_port=tcp://localhost:2009,id=enb,base_srate=23.04e6" --ric.agent.remote_ipv4_addr=${E2TERM_IP} --log.all_level=warn --ric.agent.log_level=debug --log.filename=stdout --ric.agent.local_ipv4_addr=${E2NODE_IP} --ric.agent.local_port=${E2NODE_PORT} --slicer.enable=1 --slicer.workshare=0

Terminal 3: Set up the first UE

.. code-block:: bash

    sudo srsue \
    --rf.device_name=zmq --rf.device_args="tx_port=tcp://*:2010,rx_port=tcp://localhost:2300,id=ue,base_srate=23.04e6" --usim.algo=xor --usim.imsi=001010123456789 --usim.k=00112233445566778899aabbccddeeff --usim.imei=353490069873310 --log.all_level=warn --log.filename=stdout --gw.netns=ue1

Terminal 4: Set up the second UE

.. code-block:: bash

    sudo srsue \
    --rf.device_name=zmq --rf.device_args="tx_port=tcp://*:2007,rx_port=tcp://localhost:2400,id=ue,base_srate=23.04e6" --usim.algo=xor --usim.imsi=001010123456780 --usim.k=00112233445566778899aabbccddeeff --usim.imei=353490069873310 --log.all_level=warn --log.filename=stdout --gw.netns=ue2
    
Terminal 5: Set up the third UE

.. code-block:: bash

    sudo srsue \
    --rf.device_name=zmq --rf.device_args="tx_port=tcp://*:2008,rx_port=tcp://localhost:2500,id=ue,base_srate=23.04e6" --usim.algo=xor --usim.imsi=001010123456781 --usim.k=00112233445566778899aabbccddeeff --usim.imei=353490069873310 --log.all_level=warn --log.filename=stdout --gw.netns=ue3
    
Terminal 6: Start the gnuradio flowgraph

.. code-block:: bash

    python3 multi_ue.py

Terminal 7, 8 & 9: Set up iperf3 test on the server side

.. code-block:: bash
   
    iperf3 -s -B 172.16.0.1 -p 5006 -i 1
    iperf3 -s -B 172.16.0.1 -p 5020 -i 1
    iperf3 -s -B 172.16.0.1 -p 5030 -i 1

Terminal 10, 11 & 12: Set up iperf3 test on the client side

We add an additional bandwidth argument "-b xxM" on each iperf3 test on client side to create a scenario of UEs trying to access more or less of resources on the network. If a UE surpasses the pre-determined threshold for amount of data packets transmitted, it is considered as Malicious by the DRL-SS xApp.

.. code-block:: bash

   sudo ip netns exec ue1 iperf3 -c 172.16.0.1 -p 5006 -i 1 -t 36000 -R -b 30M
   sudo ip netns exec ue2 iperf3 -c 172.16.0.1 -p 5020 -i 1 -t 36000 -R -b 10M

You should notice traffic flow on both the server and client side for both UEs. Move on to the next step.

Terminal 10

.. code-block:: bash
    
    cd drl-ss
    export KONG_PROXY=`sudo kubectl get svc -n ricplt -l app.kubernetes.io/name=kong -o jsonpath='{.items[0].spec.clusterIP}'`
    export E2MGR_HTTP=`sudo kubectl get svc -n ricplt --field-selector metadata.name=service-ricplt-e2mgr-http -o jsonpath='{.items[0].spec.clusterIP}'`
    export APPMGR_HTTP=`sudo kubectl get svc -n ricplt --field-selector metadata.name=service-ricplt-appmgr-http -o jsonpath='{.items[0].spec.clusterIP}'`
    export E2TERM_SCTP=`sudo kubectl get svc -n ricplt --field-selector metadata.name=service-ricplt-e2term-sctp-alpha -o jsonpath='{.items[0].spec.clusterIP}'`
    export ONBOARDER_HTTP=`sudo kubectl get svc -n ricplt --field-selector metadata.name=service-ricplt-xapp-onboarder-http -o jsonpath='{.items[0].spec.clusterIP}'`
    export RTMGR_HTTP=`sudo kubectl get svc -n ricplt --field-selector metadata.name=service-ricplt-rtmgr-http -o jsonpath='{.items[0].spec.clusterIP}'`

Deploying the xApp
------------------

.. code-block:: bash

    curl -L -X POST "http://$KONG_PROXY:32080/onboard/api/v1/onboard/download" --header 'Content-Type: application/json' --data-binary "@drl-ss-onboard.url"
    curl -L -X GET "http://$KONG_PROXY:32080/onboard/api/v1/charts"
    curl -L -X POST "http://$KONG_PROXY:32080/appmgr/ric/v1/xapps" --header 'Content-Type: application/json' --data-raw '{"xappName": "drl-ss"}'

Add another terminal to print the logs

.. code-block:: bash

    sudo kubectl logs -f -n ricxapp -l app=ricxapp-drl-ss

.. warning::
    Before running the rest of the commands, detach two of the terminals with the iperf3 test running for 2 UEs to observe the downlink traffic.
    Also, detach the terminal with the logs.

Now run the test script with the following commands. You have to access the test script through the root directory to execute the commands in the script. The test script has commands for creating NodeB, UEs, and slices within the xApp, as well as binding the UEs to the slices. The xApp runs it's authentication mechanism for identifying authorized UEs during the creation of UEs.

.. code-block:: bash

    chmod +x zmqtwoue.sh
    ./zmqtwoue.sh

After a short time you can observe through the logs that UE1 will be considered malicious and moved to a different slice. You also observe the traffic exchange for UE1 will significantly decrease. 

To observe the throughput changes graphically, save the iperf3 test results for both UEs on text files and run the follwing python script. Make sure to change the file name on the script to match your files.

.. code-block:: bash
    
    python3 iperfplot.py
		
An example of graph generated from running DRL-SS for with 2 UEs (one regular and one malicious) is given below:
 
 .. image:: ORAN-secure-slicing.png
    :width: 80%
    :alt: OAIC Secure Slicing Xapp

