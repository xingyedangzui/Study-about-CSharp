using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 抽象工厂模式
{
    interface IFactory
    {
        IUser CreateUser();
        IDepartment CreateDepartment();
    }
}
