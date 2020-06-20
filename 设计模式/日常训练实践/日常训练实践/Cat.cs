using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 日常训练实践
{
    class Cat
    {
        private string name;

        public Cat(string name)
        {
            this.name = name;
        }

        public delegate void CatShoutEventHandler(object sender,CatShoutEventArgs args);

        public event CatShoutEventHandler CatShout;

        public void Shout()
        {
            Console.WriteLine("喵，我是{0}", name);

            if(CatShout != null)
            {
                CatShoutEventArgs e = new CatShoutEventArgs();
                e.Name = this.name;
                CatShout(this, e);
            }
        }
    }
}
