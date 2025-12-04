#include "core/ExcelUtils.hpp"
#include "xlnt/xlnt.hpp"
#include <iostream>

void writeAccountsExcel(const string &filename, vector<Account> &accounts)
{
    xlnt::workbook wb;
    auto ws = wb.active_sheet();
    ws.title("Sheet1");

    ws.cell("A1").value("Username");
    ws.cell("B1").value("Password");

    int row = 2;
    for (auto &acc : accounts)
    {
        ws.cell("A" + to_string(row)).value(acc.getUsername());
        ws.cell("B" + to_string(row)).value(acc.getPassword());
        row++;
    }

    wb.save(filename);
    cout << "Successfully saved student records ☁️!" << endl;
}

vector<Account> readAccountsExcelToVector(const string &filename)
{
    vector<Account> account;
    xlnt::workbook wb;

    try
    {
        wb.load(filename);
    }
    catch (...)
    {
        cout << "⚠️ Couldn't open file, returning empty student list." << endl;
        return account;
    }

    auto ws = wb.active_sheet();
    for (auto row : ws.rows(false))
    {
        if (row[0].to_string() == "username")
            continue;

        string username = row[0].to_string();
        string password = row[1].to_string();
        account.emplace_back(username, password);
    }
    return account;
}

void readAccountsExcel(const string &filename)
{
    xlnt::workbook wb;
    wb.load(filename);
    auto ws = wb.active_sheet();

    for (auto row : ws.rows(false))
    {
        for (auto cell : row)
        {
            cout << cell.to_string() << " ";
        }
        cout << endl;
    }
}