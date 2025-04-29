#pragma once
#include "../Database/DBConnection.h"
#include "../Models/StockHistoryModel.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace MySql::Data::MySqlClient;

namespace PMST {
    public ref class StockHistoryController
    {
    public:
        bool CreateHistoryEntry(StockHistoryModel^ entry);
        List<StockHistoryModel^>^ GetAllHistory();
        void UpdateHistoryEntry(StockHistoryModel^ entry);
        void DeleteHistoryEntry(int id);
    };
}