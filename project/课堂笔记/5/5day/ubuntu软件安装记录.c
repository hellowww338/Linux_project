================================================
从这里开始看

ubuntu20.0.4 

安装完ubuntu20后
安装 
apt update      #更新软件源 必须能上网
apt install vim
apt install tree
apt install net-tools
apt install make
apt install gcc

apt install ssh



https://baijiahao.baidu.com/s?id=1670100505795119581&wfr=spider&for=pc
安装 samba 服务器
1，下载安装 samba 服务器
$ sudo apt-get update
$ sudo apt-get install samba samba-common
2，创建共享目录
$ mkdir shared
3，修改配置文件：/etc/samba/smb.conf
打开配置文件：
$ sudo vim /etc/samba/smb.conf
在文件末尾添加下面内容：
[share] //改为希望在 Windows 中看到共享目录的名字—自定义
path = /home/robin/shared //路径改为要共享的目录路径
browseable = yes
public = yes
available = yes
writable = yes
valid users = robin //用户名改为：当前 ubuntu 系统的用户名

[work] 
path = /home/pi/work 
browseable = yes
public = yes
available = yes
writable = yes
valid users = robin 




4，给 samba 用户 ,如：(用你自己用户名)robin 设置密码$ sudo smbpasswd -a robin
5，重启 samaba 服务
$ sudo /etc/init.d/smbd restart
[ ok ] Restarting smbd (via systemctl): smbd.service.

网络服务配置
安装 net-tools
从 ubuntu18.04 版本开始，在系统中默认不支持 ifconfig 命令进行网络状态查看，需要
安装 net-tools 方可使用
$ sudo apt-get update
$ sudo apt-get install net-tools



9.让man手册彩色显示
$ sudo vi /etc/bash.bashrc
最后添加如下:
# Highlight the color man manual
export LESS_TERMCAP_mb=$'\E[01;31m'
export LESS_TERMCAP_md=$'\E[01;31m'
export LESS_TERMCAP_me=$'\E[0m'
export LESS_TERMCAP_se=$'\E[0m'
export LESS_TERMCAP_so=$'\E[01;44;33m'
export LESS_TERMCAP_ue=$'\E[0m'
export LESS_TERMCAP_us=$'\E[01;32m'

安装配置vim
sudo apt-get install  vim   (安装完整版本的VI)

创建
vi ~/.vimrc 

添加
			
set nu				
set cindent				
set st=4				
set sts=4				
set sw=4				
let &termencoding=&encoding
set fileencodings=utf-8,gbk,ucs-bom,cp93














