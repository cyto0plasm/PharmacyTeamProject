#pragma once
#include "../Database/DBConnection.h"
#include "../Models/ProductModel.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;

namespace PMST {
    public ref class ProductsController
    {
    public:
        bool CreateProduct(ProductModel^ product);
        List<ProductModel^>^ GetAllProducts();
        void UpdateProduct(ProductModel^ product);
        void DeleteProduct(int id);
    };
}

