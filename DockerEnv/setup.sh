docker build ../DockerEnv -t myos-buildenv
docker run --rm -it -v "${pwd}:/root/env" myos-buildenv