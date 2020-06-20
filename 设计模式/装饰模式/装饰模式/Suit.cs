using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 装饰模式
{
    class Suit : Finery1
    {
        public override void Show()
        {
            Console.Write("西装 ");
            base.Show();
        }
    }
}
