
#pragma once
#include "../Database/DBConnection.h"
#include "../Models/PharmacyModel.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;

namespace PMST {
    public ref class PharmaciesController
    {
    public:
        bool CreatePharmacy(PharmacyModel^ pharmacy);
        List<PharmacyModel^>^ GetAllPharmacies();
        void UpdatePharmacy(PharmacyModel^ pharmacy);
        void DeletePharmacy(int id);
    };
}