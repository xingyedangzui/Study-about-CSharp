using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 代理模式
{
    class Proxy1 : subject
    {
        RealSubject realSubject;

        public override void Request()
        {
            if(realSubject == null)
            {
                realSubject = new RealSubject();
            }

            realSubject.Request();
        }

        static void Main(string[] args)
        {
            Proxy1 proxy = new Proxy1();
            proxy.Request();

            Console.Read();
        }
    }
}
