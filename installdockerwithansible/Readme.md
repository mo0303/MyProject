How to use 
1. cd Installdocker folder.
2. config host ip in inventory.ini and path to public key.
3. run command ansible-playbook -i inventory Installdocker.yml.
4. ansible will working with main.yml in each roles folders.
5. in common role ansible will update, create docker user and add to group, remove older version of docker, etc.
6. in docker role ansible will install docker, python dependencies,Docker SDK for python.
7. in test-run-container ansible will use docker container run command, checking nginx and show result.
Puripat Rattanayuenyong