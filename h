[33mcommit 66c78bd066670813ccd7d96930c2f92c637ba131[m[33m ([m[1;36mHEAD[m[33m -> [m[1;32mmaster[m[33m)[m
Author: aedelnz <aedelnz@qq.com>
Date:   Sun Jun 1 17:09:00 2025 +0800

    内容优化

[1mdiff --git a/public/config.js b/public/config.js[m
[1mindex 656cb44..a101b8f 100644[m
[1m--- a/public/config.js[m
[1m+++ b/public/config.js[m
[36m@@ -12,14 +12,15 @@[m [mwindow.Config = {[m
   // 日志天数[m
   CountDays: 30,[m
 [m
[31m-  // 是否显示检测站点的链接[m
[31m-  ShowLink: true,[m
[31m-[m
   // 导航栏菜单[m
   Navi: [[m
     {[m
       text: '主页',[m
[31m-      url: 'https://jixiejidiguan.top/'[m
[31m-    }[m
[32m+[m[32m      url: 'https://jixiejidiguan.top'[m
[32m+[m[32m    },{[m
[32m+[m[32m      text: '原页',[m
[32m+[m[32m      url: 'https://stats.uptimerobot.com/0M2zqUkp83'[m
[32m+[m[32m    },[m
[32m+[m
   ],[m
 };[m
[1mdiff --git a/public/favicon.ico b/public/favicon.ico[m
[1mdeleted file mode 100644[m
[1mindex 989c977..0000000[m
Binary files a/public/favicon.ico and /dev/null differ
[1mdiff --git a/public/favicon.png b/public/favicon.png[m
[1mnew file mode 100644[m
[1mindex 0000000..f75ad92[m
Binary files /dev/null and b/public/favicon.png differ
[1mdiff --git a/public/index.html b/public/index.html[m
[1mindex 01de912..fc2a5d0 100644[m
[1m--- a/public/index.html[m
[1m+++ b/public/index.html[m
[36m@@ -1,16 +1,13 @@[m
 <!DOCTYPE html>[m
 <html>[m
[31m-  <head>[m
[31m-    <meta charset="utf-8" />[m
[31m-    <meta[m
[31m-      name="viewport"[m
[31m-      content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no"[m
[31m-    />[m
[31m-    <link rel="shortcut icon" href="./favicon.ico" type="image/x-icon" />[m
[31m-    <title>site-status</title>[m
[31m-    <script src="./config.js"></script>[m
[31m-  </head>[m
[31m-  <body>[m
[31m-    <div id="app"></div>[m
[31m-  </body>[m
[32m+[m[32m<head>[m
[32m+[m[32m<meta charset="utf-8" />[m
[32m+[m[32m<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no"/>[m
[32m+[m[32m<link rel="shortcut icon" href="./favicon.png" type="image/x-icon"/>[m
[32m+[m[32m<title>site-status</title>[m
[32m+[m[32m<script src="./config.js"></script>[m
[32m+[m[32m</head>[m
[32m+[m[32m<body>[m
[32m+[m[32m<div id="app"></div>[m
[32m+[m[32m</body>[m
 </html>[m
[1mdiff --git a/src/app.scss b/src/app.scss[m
[1mindex 9de3afe..6fe67d0 100644[m
[1m--- a/src/app.scss[m
[1m+++ b/src/app.scss[m
[36m@@ -6,6 +6,7 @@[m [m$primary-color: #3bd672;[m
 }[m
 [m
 body {[m
[32m+[m[32m  margin-top: 84px;[m
   font-family: sans-serif;[m
   font-size: 18px;[m
   line-height: 1;[m
[36m@@ -22,22 +23,31 @@[m [ma {[m
     width: 100%;[m
     max-width: 980px;[m
     margin: 0 auto;[m
[31m-    padding: 0 20px;[m
   }[m
 }[m
 [m
 #header {[m
[31m-  background-color: #121a26;[m
[31m-  padding: 30px 0 200px 0;[m
[31m-  color: $primary-color;[m
[31m-  width: 100%;[m
[32m+[m[32m  position: fixed;[m
[32m+[m[32m  top: 0;[m
[32m+[m[32m  left: 0;[m
[32m+[m[32m  right: 0;[m
[32m+[m[32m  height: 64px; /* 标准高度 */[m
[32m+[m[32m  background-color: #6200ee; /* 主色 */[m
[32m+[m[32m  color: white;[m
[32m+[m[32m  display: flex;[m
[32m+[m[32m  align-items: center;[m
[32m+[m[32m  justify-content: space-between;[m
[32m+[m[32m  padding: 0 16px;[m
[32m+[m[32m  box-shadow: 0 2px 8px rgba(0, 0, 0, .8);[m
[32m+[m[32m  z-index: 1000; /* 确保在其他内容之上 */[m
[32m+[m
   .container {[m
     display: flex;[m
     align-items: baseline;[m
     justify-content: space-between;[m
   }[m
   .logo {[m
[31m-    font-size: 20px;[m
[32m+[m[32m    font-size: 24px;[m
     font-weight: bold;[m
   }[m
   .navi {[m
[36m@@ -55,61 +65,42 @@[m [ma {[m
 [m
 #uptime {[m
   background-color: #ffffff;[m
[31m-  border-radius: 10px;[m
[31m-  box-shadow: 0 10px 30px rgba(0, 0, 0, 0.1);[m
[31m-  margin-top: -30px;[m
[32m+[m[32m  box-shadow: 0 4px 10px rgba(0, 0, 0, 0.6);[m
   margin-bottom: 40px;[m
[31m-  padding: 15px 0;[m
[32m+[m[32m  padding: 8px 0;[m
   overflow: hidden;[m
   .site {[m
[31m-    border-bottom: 1px solid #e6e7e8;[m
[31m-    margin: 0 30px;[m
[31m-    padding: 25px 0;[m
[32m+[m[32m    border-bottom: 1px solid #000;[m
[32m+[m[32m    margin: 0 8px;[m
[32m+[m[32m    padding: 8px 0;[m
     .loading {[m
       background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 50 50'%3E%3Cpath fill='%23D6D8D8' d='M19.52 42.712c9.897 2.916 20.285-2.743 23.201-12.64l-3.902-1.15c-2.281 7.742-10.407 12.17-18.15 9.888l-1.15 3.902z'%3E%3CanimateTransform attributeType='xml' attributeName='transform' type='rotate' from='0 25 25' to='360 25 25' dur='0.6s' repeatCount='indefinite'/%3E%3C/path%3E%3C/svg%3E");[m
       background-repeat: no-repeat;[m
       background-size: 100% 100%;[m
       display: block;[m
       margin: 0 auto;[m
[31m-      width: 40px;[m
[31m-      height: 40px;[m
[32m+[m[32m      width: 10rem;[m
[32m+[m[32m      height: 10rem;[m
     }[m
     .meta {[m
       display: flex;[m
       align-items: baseline;[m
[31m-      .name {[m
[31m-        font-size: 16px;[m
[31m-      }[m
       .link {[m
[31m-        background-image: url("data:image/svg+xml,%3Csvg class='icon' viewBox='0 0 1036 1024' xmlns='http://www.w3.org/2000/svg'%3E%3Cpath d='M600.818 697.6c-70.4 0-134.4-25.6-192-76.8-25.6-25.6-25.6-64-6.4-89.6 25.6-25.6 64-25.6 89.6-6.4 57.6 51.2 147.2 51.2 198.4 0l166.4-166.4c25.6-25.6 38.4-64 38.4-102.4 0-25.6-6.4-64-38.4-96-57.6-51.2-147.2-51.2-198.4 0l-64 76.8c-25.6 25.6-64 25.6-89.6 0-25.6-25.6-25.6-64 0-89.6l70.4-70.4c102.4-102.4 268.8-102.4 377.6 0 51.2 51.2 83.2 115.2 83.2 192 0 70.4-25.6 134.4-76.8 192l-166.4 166.4c-57.6 44.8-121.6 70.4-192 70.4z' fill='%238492A6'/%3E%3Cpath d='M274.418 1024c-70.4 0-134.4-25.6-192-76.8-108.8-96-108.8-262.4-6.4-377.6l166.4-166.4c108.8-102.4 275.2-102.4 377.6 0 25.6 25.6 25.6 64 0 89.6s-64 25.6-89.6 0c-51.2-51.2-140.8-51.2-198.4 0l-166.4 166.4c-44.8 51.2-64 140.8 0 198.4 57.6 51.2 147.2 51.2 198.4 0l70.4-70.4c25.6-25.6 64-25.6 89.6 0s25.6 64 0 89.6l-70.4 70.4c-44.8 51.2-108.8 76.8-179.2 76.8z' fill='%238492A6'/%3E%3C/svg%3E");[m
[31m-        background-size: 100% 100%;[m
[31m-        background-repeat: no-repeat;[m
[31m-        width: 13px;[m
[31m-        height: 13px;[m
[31m-        text-indent: -99999px;[m
[31m-        margin-left: 8px;[m
[31m-        opacity: 0.6;[m
[31m-        transition: opacity ease 150ms;[m
[31m-        &:hover {[m
[31m-          opacity: 1;[m
[31m-        }[m
[32m+[m[32m        font-size: 1.25rem;[m
[32m+[m[32m        font-weight: bold;[m
       }[m
       .status {[m
         background-position: left center;[m
[31m-        background-size: 14px auto;[m
[32m+[m[32m        background-size: 10px auto;[m
         background-repeat: no-repeat;[m
[31m-        padding-left: 20px;[m
         margin-left: auto;[m
         &.ok {[m
[31m-          background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='12' height='10'%3E%3Cpath fill-rule='evenodd' clip-rule='evenodd' d='M12 2l-8 8-4-4 1.5-1.5L4 7 10.5.5 12 2z' fill='%233bd672'/%3E%3C/svg%3E");[m
           color: $primary-color;[m
         }[m
         &.fail {[m
[31m-          background-image: url("data:image/svg+xml,%3Csvg viewBox='0 0 1064 1024' xmlns='http://www.w3.org/2000/svg'%3E%3Cpath d='M205.09 959.373l327.82-327.83 327.827 327.83L981.31 838.79 653.49 510.97l327.82-327.814L860.737 62.58 532.91 390.4 205.09 62.581 84.527 183.155l327.82 327.814-327.82 327.82z' fill='%23DE484A'/%3E%3C/svg%3E");[m
           color: #de484a;[m
         }[m
         &.unknow {[m
[31m-          background-image: url("data:image/svg+xml,%3Csvg viewBox='0 0 1024 1024' xmlns='http://www.w3.org/2000/svg'%3E%3Cpath d='M521.216 164.864c161.792 0 199.68 149.504 106.496 242.688C523.264 512 441.344 532.48 441.344 749.568h158.72c1.024-123.904 62.464-182.272 125.952-239.616 58.368-53.248 120.832-99.328 120.832-206.848 0-171.008-159.744-292.864-325.632-292.864-187.392 0-344.064 132.096-344.064 316.416h158.72c0-92.16 92.16-161.792 185.344-161.792M441.344 855.04h158.72v158.72h-158.72V855.04z' fill='%23969ea8'/%3E%3C/svg%3E");[m
           color: #969ea8;[m
         }[m
       }[m
[36m@@ -117,13 +108,13 @@[m [ma {[m
     .timeline {[m
       display: flex;[m
       justify-content: space-between;[m
[31m-      margin: 15px 0 10px 0;[m
[32m+[m[32m      margin: 8px 0 6px 0;[m
       i {[m
         flex-grow: 1;[m
         margin: 0 1px;[m
[31m-        height: 25px;[m
[31m-        border-radius: 5px;[m
[31m-        transition: opacity ease 150ms;[m
[32m+[m[32m        height: 2rem;[m
[32m+[m[32m        border-radius: 2px;[m
[32m+[m[32m        transition: opacity ease 1500ms;[m
         &.ok {[m
           background-color: $primary-color;[m
         }[m
[36m@@ -147,13 +138,13 @@[m [ma {[m
     .summary {[m
       display: flex;[m
       justify-content: space-between;[m
[31m-      font-size: 13px;[m
[31m-      line-height: 15px;[m
[32m+[m[32m      font-size: 10px;[m
[32m+[m[32m      line-height: 10px;[m
       color: #9aa2af;[m
     }[m
     .tooltip {[m
[31m-      padding: 6px 9px !important;[m
[31m-      border-radius: 5px !important;[m
[32m+[m[32m      padding: 2px 6px !important;[m
[32m+[m[32m      border-radius: 2px !important;[m
     }[m
   }[m
   .site:last-child {[m
[36m@@ -162,12 +153,13 @@[m [ma {[m
 }[m
 [m
 #footer {[m
[31m-  font-size: 12px;[m
[32m+[m[32m  margin-top: 1rem;[m
[32m+[m[32m  margin-bottom: 1rem;[m
[32m+[m[32m  font-size: .7rem;[m
   text-align: center;[m
[31m-  line-height: 25px;[m
[32m+[m[32m  line-height: .8rem;[m
   color: #969ea8;[m
   a {[m
     font-weight: bold;[m
[31m-    color: $primary-color;[m
   }[m
 }[m
[1mdiff --git a/src/components/app.js b/src/components/app.js[m
[1mindex e1912a8..86a4dbc 100644[m
[1m--- a/src/components/app.js[m
[1m+++ b/src/components/app.js[m
[36m@@ -23,8 +23,8 @@[m [mfunction App() {[m
           ))}[m
         </div>[m
         <div id='footer'>[m
[31m-          <p>基于 <Link to='https://uptimerobot.com/' text='UptimeRobot' /> 接口制作，检测频率 5 分钟</p>[m
[31m-          <p>&copy; 2020 <Link to='https://starts.jixiejidiguan.eu.org' text='starts.jixiejidiguan.eu.org' />, Version {Package.version}</p>[m
[32m+[m[32m          <p>基于 <Link to='https://uptimerobot.com/' text='UptimeRobot' /> 接口制作，检测频率 5 分钟，Version {Package.version}</p>[m
[32m+[m[32m          <p>Copyright © 2020 - 2025 <Link to="https://jixiejidiguan.top" text="画的个人记录"/>. All Rights Reserved.</p>[m
         </div>[m
       </div>[m
     </>[m
[1mdiff --git a/src/components/uptimerobot.js b/src/components/uptimerobot.js[m
[1mindex 4f6ee9b..cc45d17 100644[m
[1m--- a/src/components/uptimerobot.js[m
[1m+++ b/src/components/uptimerobot.js[m
[36m@@ -12,7 +12,7 @@[m [mfunction UptimeRobot({ apikey }) {[m
     unknow: '未知'[m
   };[m
 [m
[31m-  const { CountDays, ShowLink } = window.Config;[m
[32m+[m[32m  const { CountDays } = window.Config;[m
 [m
   const [monitors, setMonitors] = useState();[m
 [m
[36m@@ -23,8 +23,7 @@[m [mfunction UptimeRobot({ apikey }) {[m
   if (monitors) return monitors.map((site) => ([m
     <div key={site.id} className='site'>[m
       <div className='meta'>[m
[31m-        <span className='name' dangerouslySetInnerHTML={{ __html: site.name }} />[m
[31m-        {ShowLink && <Link className='link' to={site.url} text={site.name} />}[m
[32m+[m[32m        <Link className='link' to={site.url} text={site.name} />[m
         <span className={'status ' + site.status}>{status[site.status]}</span>[m
       </div>[m
       <div className='timeline'>[m
[1mdiff --git a/src/index.js b/src/index.js[m
[1mindex 6c5a050..4625bbb 100644[m
[1m--- a/src/index.js[m
[1m+++ b/src/index.js[m
[36m@@ -4,9 +4,9 @@[m [mimport App from './components/app';[m
 import './app.scss';[m
 [m
 const root = ReactDOM.createRoot(document.getElementById('app'));[m
[31m-root.render(<App />);[m
[31m-// root.render([m
[31m-//   <React.StrictMode>[m
[31m-//     <App />[m
[31m-//   </React.StrictMode>[m
[31m-// );[m
[32m+[m[32m//root.render(<App />);[m
[32m+[m[32m root.render([m
[32m+[m[32m   <React.StrictMode>[m
[32m+[m[32m     <App />[m
[32m+[m[32m   </React.StrictMode>[m
[32m+[m[32m );[m
