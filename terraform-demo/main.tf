terraform {
  required_providers {
    docker = {
        source = "kreuzwerker/docker"
        version = "2.16.0"
    }
  }
}

provider "docker" {
  host    = "npipe:////.//pipe//docker_engine"
}


variable "nginx_external_port" {
  type = number
  description = "Port to map from nginx to docker host"
  
}

variable "nginx_external_port" {
  type = number
  description = "Port to map from nginx to docker host"
  
}

resource "docker_container" "my_tf_container" {
  image = docker_image.my_nginx_image.latest
  name = "my_terraform_nginx_container_xx"
  ports {
    internal =  80
    external = var.nginx_external_port
  }
  
}

resource "docker_image" "my_nginx_image" {
  name = "nginx:latest"
  
}