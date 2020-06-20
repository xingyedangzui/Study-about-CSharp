using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 代理模式
{
    class RealSubject : subject
    {
        public override void Request()
        {
            Console.WriteLine("真实的请求");
        }
    }
}
