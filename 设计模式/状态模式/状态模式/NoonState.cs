using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 状态模式
{
    //中午工作状态
    public class NoonState : State
    {
        public override void WriteProgram(Work w)
        {
            if(w.Hour<13)
            {
                Console.WriteLine("当前时间：{0} 饿了，午饭；犯困，午休。", w.Hour);
            }
            else
            {
                w.SetState(new AfternoonState());
                w.WriteProgram();
            }
        }
    }
}
