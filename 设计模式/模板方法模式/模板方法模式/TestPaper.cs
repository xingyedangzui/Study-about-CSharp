using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 模板方法模式
{
    class TestPaper
    {
        public void TestQuestion1()
        {
            Console.WriteLine("问题1: ");
            Console.WriteLine("答案： " + Answer1());
        }

        protected virtual string Answer1()
        {
            return " ";
        }
    }
}
