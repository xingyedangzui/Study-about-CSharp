using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 日常训练实践
{
    class GrandFather
    {
        protected string mm_name = "赵日宇宙";

        public GrandFather()
        {
            Console.WriteLine("爷爷");
        }
    }

    class Father : GrandFather
    {
        public Father()
        {
            Console.WriteLine("父亲");
        }

        protected string m_name;
        private int m_age;

        public void SetName(string name)
        {
            this.m_name = name;
        }
        public string GetName()
        {
            return m_name;
        }

        public int Age
        {
            get { return m_age; }
            set { m_age = value; }
        }
    }

    class Sonson : Father
    {
        public Sonson()
        {
            Console.WriteLine("孙子");
            Console.WriteLine(m_name);
        }
    }

    class Son : Father
    {
        public Son()
        {
            Console.WriteLine("儿子");
            base.SetName("赵日天");
        }

        public void use()
        {
            Console.WriteLine(m_name);
            Console.WriteLine(base.m_name);
            Console.WriteLine(m_name);
            Console.WriteLine(base.m_name);
            Console.WriteLine(mm_name);
            Console.WriteLine(base.mm_name);
            this.mm_name = "赵日宇宙宙";
            Console.WriteLine(mm_name);
            Console.WriteLine(base.mm_name);
            base.mm_name = "赵日宇宙宙宙周";
            Console.WriteLine(mm_name);
            Console.WriteLine(base.mm_name);
            Sonson sonson = new Sonson();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Cat cat = new Cat("Tom");

            Mouse mouse1 = new Mouse("Jerry");
            Mouse mouse2 = new Mouse("Jack");

            cat.CatShout += new Cat.CatShoutEventHandler(mouse1.Run);
            cat.CatShout += new Cat.CatShoutEventHandler(mouse2.Run);

            cat.Shout();

            Console.Read();
        }
    }
}
