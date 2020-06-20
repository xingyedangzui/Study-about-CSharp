using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 适配器模式
{
    //翻译者
    public class Translater : Player
    {
        private ForeignCenter wjzf = new ForeignCenter();

        public Translater(string name) : base (name)
        {
            wjzf.Name = name;
        }

        public override void Attack()
        {
            wjzf.进攻();
        }

        public override void Defence()
        {
            wjzf.防守();
        }
    }
}
