
#pragma once
#include "../Database/DBConnection.h"
#include "../Models/SupplierModel.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;

namespace PMST {
    public ref class SuppliersController
    {
    public:
        bool CreateSupplier(SupplierModel^ supplier);
        List<SupplierModel^>^ GetAllSuppliers();
        void UpdateSupplier(SupplierModel^ supplier);
        void DeleteSupplier(int id);
    };
}