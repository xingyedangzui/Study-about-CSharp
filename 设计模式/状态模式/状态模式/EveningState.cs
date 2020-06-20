using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 状态模式
{
    //晚间工作状态
    public class EveningState : State
    {
        public override void WriteProgram(Work w)
        {
            if(w.TaskFinished)
            {
                w.SetState(new RestState());
                w.WriteProgram();
            }
            else
            {
                if(w.Hour<21)
                {
                    Console.WriteLine("当前时间：{0}点 加班哦，疲劳至极", w.Hour);
                }
                else
                {
                    w.SetState(new SleepingState());
                    w.WriteProgram();
                }
            }
        }

    }
}
