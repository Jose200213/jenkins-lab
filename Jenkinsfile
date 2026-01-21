pipeline {
    agent {
        kubernetes {
            // Este es el nombre que tendrá el pod
            yaml """
apiVersion: v1
kind: Pod
metadata:
  labels:
    some-label: some-value
spec:
  containers:
  - name: jnlp
    image: mi-agente-cpp:v1
    imagePullPolicy: Never
    tty: true
"""
        }
    }
    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        stage('Compilar') {
            steps {
                sh 'g++ wersja-x.cpp -o mi_programa'
            }
        }
        stage('Verificar') {
            steps {
                sh 'mkdir -p /tmp/smok/program-cpp' 
                sh './mi_programa'
            }
        }
    }
}
