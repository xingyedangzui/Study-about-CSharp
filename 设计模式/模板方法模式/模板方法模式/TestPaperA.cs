using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 模板方法模式
{
    class TestPaperA : TestPaper
    {
        protected override string Answer1()
        {
            return "b";
        }
    }
}
