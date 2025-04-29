#pragma once
#include "../Database/DBConnection.h"
#include "../Models/SaleModel.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;

namespace PMST {
    public ref class SalesController
    {
    public:
        bool CreateSale(SaleModel^ sale);
        List<SaleModel^>^ GetAllSales();
        void UpdateSale(SaleModel^ sale);
        void DeleteSale(int id);
    };
}