# Usamos la imagen base oficial del agente de Jenkins
FROM jenkins/inbound-agent:latest

# Nos convertimos en usuario 'root' para poder instalar cosas
USER root

# Instalamos g++ (el compilador) y make
RUN apt-get update && apt-get install -y build-essential

# Volvemos a ser el usuario 'jenkins' por seguridad
USER jenkins
