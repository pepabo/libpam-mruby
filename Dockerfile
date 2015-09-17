FROM centos:7
MAINTAINER kentarok@gmail.com

RUN yum -y install gcc bison
RUN yum -y install pam pam-devel
RUN yum -y install git rake

ADD . /usr/local/src/libpam-mruby
WORKDIR /usr/local/src/libpam-mruby
RUN rake

