import { useMemo, useState, useCallback } from 'react';
import Link from './link';
import Header from './header';
import UptimeRobot from './uptimerobot';
import Package from '../../package.json';

function App() {

  const apikeys = useMemo(() => {
    const { ApiKeys } = window.Config; if (Array.isArray(ApiKeys)) return ApiKeys; if (typeof ApiKeys === 'string') return [ApiKeys]; return []
  }, []);
  const [monitors, setMonitors] = useState([]);
  const handleMonitorsUpdate = useCallback((newMonitors) => { setMonitors((prev) => newMonitors ? [...prev, ...newMonitors] : prev) }, []);
  const totalMonitors = monitors.length;
  const downMonitors = monitors.filter((m) => m.status === 'down').length;
  const statusText = totalMonitors === 0 ? '加载中...' : `当前有 ${totalMonitors} 个 站点 正在使用中${downMonitors > 0 ? `，其中有 ${downMonitors} 个异常` : '，全部正常'}。`;

  return (
    <>
      <Header />
      <div className='container'>
        <div id='status'>{statusText}</div>
        <div id='uptime'>
          {apikeys.map((key) => (
            <UptimeRobot key={key} apikey={key} onUpdate={handleMonitorsUpdate} />
          ))}
        </div>
        <div id='footer'>
          <p>基于 <Link to='https://uptimerobot.com/' text='UptimeRobot' /> 接口制作，检测频率 5 分钟</p>
          <p>&copy; {new Date().getFullYear()} <Link to='https://jixiejidiguan.top/' text='画的个人记录' />, Version {Package.version}</p>
        </div>
      </div>
    </>
  );
}

export default App;
