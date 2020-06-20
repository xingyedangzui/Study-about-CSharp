using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 日常训练实践
{
    class Mouse
    {
        private string name;

        public Mouse(string name)
        {
            this.name = name;
        }

        public void Run(object sender,CatShoutEventArgs args)
        {
            Console.WriteLine("猫{0}来了 ,{1}快跑！",args.Name,name);
        }
    }
}
