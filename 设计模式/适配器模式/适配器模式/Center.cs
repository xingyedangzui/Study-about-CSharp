using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 适配器模式
{
    //中锋
    public class Center : Player
    {
         public Center(string name) : base(name)
        {

        }

        public override void Attack()
        {
            Console.WriteLine("中锋 {0} 进攻", name);
        }

        public override void Defence()
        {
            Console.WriteLine("中锋 {0} 防守", name);
        }
    }
}
