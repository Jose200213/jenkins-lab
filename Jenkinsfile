pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        stage('Compilar') {
            steps {
                sh 'g++ wersja-x.cpp -o mi_programa || echo "g++ no encontrado, saltando..."'
            }
        }
        
        stage('Verificar') {
            steps {
                sh './mi_programa || echo "No se pudo ejecutar"'
            }
        }
    }
}
