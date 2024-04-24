# 设置查看IP地址

[TOC]

## Linux ip 命令

Linux ip 命令与 ifconfig 命令类似，但比 ifconfig 命令更加强大，主要功能是用于显示或设置网络设备。

ip 命令是 Linux 加强版的的网络配置工具，用于代替 ifconfig 命令。

  ### 实例

  ```
  ip link show                     # 显示网络接口信息
  ip link set eth0 up             # 开启网卡
  ip link set eth0 down            # 关闭网卡
  ip link set eth0 promisc on      # 开启网卡的混合模式
  ip link set eth0 promisc offi    # 关闭网卡的混个模式
  ip link set eth0 txqueuelen 1200 # 设置网卡队列长度
  ip link set eth0 mtu 1400        # 设置网卡最大传输单元
  ip addr show     # 显示网卡IP信息
  ip addr add 192.168.0.1/24 dev eth0 # 设置eth0网卡IP地址192.168.0.1
  ip addr del 192.168.0.1/24 dev eth0 # 删除eth0网卡IP地址
  
  ip route show # 显示系统路由
  ip route add default via 192.168.1.254   # 设置系统默认路由
  ip route list                 # 查看路由信息
  ip route add 192.168.4.0/24  via  192.168.0.254 dev eth0 # 设置192.168.4.0网段的网关为192.168.0.254,数据走eth0接口
  ip route add default via  192.168.0.254  dev eth0        # 设置默认网关为192.168.0.254
  ip route del 192.168.4.0/24   # 删除192.168.4.0网段的网关
  ip route del default          # 删除默认路由
  ip route delete 192.168.1.0/24 dev eth0 # 删除路由
  ```


## Linux ifconfig命令

Linux ifconfig命令用于显示或设置网络设备。

ifconfig可设置网络设备的状态，或是显示目前的设置。

### 实例

显示网络设备信息

```
ifconfig        
```

启动关闭指定网卡

```
ifconfig eth0 down
ifconfig eth0 up
```

为网卡配置和删除IPv6地址

```
ifconfig eth0 add 33ffe:3240:800:1005::2/ 64 //为网卡设置IPv6地址

ifconfig eth0 del 33ffe:3240:800:1005::2/ 64 //为网卡删除IPv6地址
```

用ifconfig修改MAC地址

```
ifconfig eth0 down //关闭网卡
ifconfig eth0 hw ether 00:AA:BB:CC:DD:EE //修改MAC地址
ifconfig eth0 up //启动网卡
ifconfig eth1 hw ether 00:1D:1C:1D:1E //关闭网卡并修改MAC地址 
ifconfig eth1 up //启动网卡
```

配置IP地址

```
ifconfig eth0 192.168.1.56 
//给eth0网卡配置IP地址
ifconfig eth0 192.168.1.56 netmask 255.255.255.0 
// 给eth0网卡配置IP地址,并加上子掩码
ifconfig eth0 192.168.1.56 netmask 255.255.255.0 broadcast 192.168.1.255
// 给eth0网卡配置IP地址,加上子掩码,加上个广播地址
```

启用和关闭ARP协议

```
ifconfig eth0 arp  //开启
ifconfig eth0 -arp  //关闭
```

设置最大传输单元

```
ifconfig eth0 mtu 1500 
//设置能通过的最大数据包大小为 1500 bytes
```
