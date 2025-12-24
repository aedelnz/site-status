# uptime-status

一个基于 UptimeRobot API 的在线状态面板


## 事先准备

- 您需要先到 [UptimeRobot](https://uptimerobot.com/ "UptimeRobot") 添加站点监控，并在 My Settings 页面获取 API Key
- 您需要拥有一个网站空间，常见的 Nginx / PHP 等空间即可，甚至是阿里云的 OSS 等纯静态空间也行

## 如何部署

获取

```bash
git clone https://github.com/aedelnz/site-status.git
cd site-status
```

开发
```bash
npm start
```

生产
```bash
npm build
```

## 接口代理

对于想自己搭建接口的代理的，可以参考以下 nginx 的配置文件：

```
server {
  listen [::]:80;
  server_name 解析域名;
  location / {
    proxy_ssl_server_name on;
    proxy_pass https://api.uptimerobot.com/;
    proxy_hide_header Access-Control-Allow-Origin;
    add_header Access-Control-Allow-Origin * always;
  }
}
```
