using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 备忘录模式
{
    class Memento
    {
        private string state;
        public string State
        {
            get { return state; }
        }

        public Memento(string state)
        {
            this.state = state;
        }
    }
}
