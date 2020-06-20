using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 组合模式
{
    //人力资源部
    class HRDepartment:Company
    {
        public HRDepartment(string name):base(name)
        { }

        public override void Add(Company c)
        { }

        public override void Remove(Company c)
        {
            
        }

        public override void Display(int depth)
        {
            Console.WriteLine(new String('-', depth) + name);
        }

        public override void LineOfDuty()
        {
            Console.WriteLine("{0} 员工招聘培训管理", name);
        }
    }
}
