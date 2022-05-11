//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
edtC_Id->Text ="";
edtC_Name->Text ="";
edtC_Sex->Text ="";
edtC_Tel->Text ="";
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------

void __fastcall TForm1::BtnListClick(TObject *Sender)
{
customer->Close();
customer->Open();
customer->First();
ShowData();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnNextClick(TObject *Sender)
{

customer->Open();
customer->Next();
ShowData();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnPriorClick(TObject *Sender)
{
customer->Open();
customer->Prior();
ShowData();
}
//---------------------------------------------------------------------------


void TForm1::ShowData(){
edtC_Id->Text=customer->FieldValues["C_ID"];
edtC_Name->Text=customer->FieldValues["C_NAME"];
edtC_Sex->Text=customer->FieldValues["C_SEX"];
edtC_Tel->Text=customer->FieldValues["C_TEL"];
}
void __fastcall TForm1::BtnChangeClick(TObject *Sender)
{
if(MessageBox(NULL,"确认信息无误","确认",33)==IDOK){
customer->Edit();
customer->FieldValues["C_ID"]=edtC_Id->Text;
customer->FieldValues["C_NAME"]=edtC_Name->Text;
customer->FieldValues["C_SEX"]=edtC_Sex->Text;
customer->FieldValues["C_TEL"]=edtC_Tel->Text;
customer->Post();
ShowData();
BtnChange->Caption="修改数据";
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnDeleteClick(TObject *Sender)
{
if(MessageBox(NULL,"确认删除","警告",49)==IDOK){
customer->Delete();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnAddClick(TObject *Sender)
{
ShowMessage("数据输入后，请单击“确认”按钮更新DB");
BtnChange->Caption="确认";
customer->Append();
}
//---------------------------------------------------------------------------

