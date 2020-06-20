﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 状态模式
{
    //睡眠状态
    public class SleepingState:State
    {
        public override void WriteProgram(Work w)
        {
            Console.WriteLine("当前时间：{0}点不行了，睡着了。", w.Hour);
        }
    }
}
