using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 组合模式
{
    //财务部
    class FinanceDepartment:Company
    {
        public FinanceDepartment(string name):base(name)
        {

        }

        public override void Add(Company c)
        {
            
        }

        public override void Remove(Company c)
        {
            
        }

        public override void Display(int depth)
        {
            Console.WriteLine(new String('-', depth) + name);
        }

        public override void LineOfDuty()
        {
            Console.WriteLine("{0} 公司财务收支管理", name);
        }
    }
}
