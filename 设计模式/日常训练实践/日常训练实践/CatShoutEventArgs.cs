using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 日常训练实践
{
    class CatShoutEventArgs : EventArgs
    {
        private string name;

        public string Name
        {
            get { return name; }
            set { name = value; }
        }
    }
}
