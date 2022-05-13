//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Word_2K_SRVR"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    // text文本框数据初始化
    edtC_Id->Text ="";
    edtC_Name->Text ="";
    edtC_Sex->Text ="";
    edtC_Tel->Text ="";
    
    // 切换ListView的显示风格为详细信息
    ListView1->ViewStyle = vsReport;
 
    // 清除ListView所有列和行的内容
    ListView1->Columns->Clear();
    
    // 标题创建
    ListTitleCreat();
}
//---------------------------------------------------------------------------

void TForm1::ShowData(){

    // 数据表示
    customer->Open();
    edtC_Id->Text=customer->FieldValues["C_ID"];
    edtC_Name->Text=customer->FieldValues["C_NAME"];
    edtC_Sex->Text=customer->FieldValues["C_SEX"];
    edtC_Tel->Text=customer->FieldValues["C_TEL"];
}
//---------------------------------------------------------------------------

void TForm1::ListTitleCreat(){
    // 添加第一列
    TListColumn *lc = ListView1->Columns->Add();
    lc->Caption = "员工卡号";
    lc->Width = 120;
 
    // 添加第二列
    lc = ListView1->Columns->Add();
    lc->Caption = "员工姓名";
    lc->Width = 125;
 
    // 添加第三列
    lc = ListView1->Columns->Add();
    lc->Caption = "员工性别";
    lc->Width = 125;

    // 添加第四列
    lc = ListView1->Columns->Add();
    lc->Caption = "员工电话";
    lc->Width = 130;
}
//---------------------------------------------------------------------------

void TForm1::ListDataShow(){
    // 按钮点击时数据清空
    ListView1->Items->Clear();
    // 禁止用户直接修改节点的标题
    ListView1->ReadOnly=true;
    customer->Close();
    customer->Open();
    // 添加数据
    while(!customer->Eof){
        TListItem *li = ListView1->Items->Add();
        li->Caption = customer->FieldValues["C_ID"];
        li->SubItems->Add(customer->FieldValues["C_NAME"]);
        li->SubItems->Add(customer->FieldValues["C_SEX"]);
        li->SubItems->Add(customer->FieldValues["C_TEL"]);
        customer->Next();
    }
    
    // 当鼠标指针移动到节点上时，改变字体颜色为蓝色
    ListView1->HotTrack=true;
    // 允许整行选中
    ListView1->RowSelect = true;
    // 设置指定的行处于选中状态，行号从0开始
    // ListView1->Items->Item[0]->Selected=True;
    // 获得焦点
    // ListView1->SetFocus();
    customer->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnFristClick(TObject *Sender)
{
    customer->Close();
    customer->Open();
    customer->First();
    // 文本框数据表示
    ShowData();
    customer->Close();
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
        BtnChange->Caption="修改";
        ListDataShow();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnDeleteClick(TObject *Sender)
{
    if(MessageBox(NULL,"确认删除","警告",49)==IDOK){
        customer->Open();
        customer->Delete();
        ListDataShow();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnAddClick(TObject *Sender)
{
    customer->Open();
    ShowMessage("数据输入后，请单击“确认”按钮更新DB");
    // text文本框数据初始化
    edtC_Id->Text ="";
    edtC_Name->Text ="";
    edtC_Sex->Text ="";
    edtC_Tel->Text ="";
    BtnChange->Caption="确认";
    customer->Append();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BtnListClick(TObject *Sender)
{
    ListDataShow();

}
//---------------------------------------------------------------------------


void __fastcall TForm1::BtnEndClick(TObject *Sender)
{
    customer->Open();
    customer->Last();
    // 文本框数据表示
    ShowData();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnSelectClick(TObject *Sender)
{
    // 取得选中节点的文本
    if(ListView1->Selected != NULL){
        // 取得选中行的行号
        int i =ListView1->Selected->Index;
        edtC_Id->Text = ListView1->Selected->Caption;
        edtC_Name->Text = ListView1->Items->Item[i]->SubItems->Strings[0];
        edtC_Sex->Text = ListView1->Items->Item[i]->SubItems->Strings[1];
        edtC_Tel->Text = ListView1->Items->Item[i]->SubItems->Strings[2];
        customer->Open();
        customer->MoveBy(i);
        
    } else {
         ShowMessage("没有选中任何数据，请确认！");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnExitClick(TObject *Sender)
{
    customer->Close();
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnPrivewClick(TObject *Sender)
{
        if(customer->Active==false){
            customer->Active=true;
            Form2->QuickRep1->PreviewModal();
        }
}
//---------------------------------------------------------------------------

