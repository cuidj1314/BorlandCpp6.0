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
    // text�ı������ݳ�ʼ��
    edtC_Id->Text ="";
    edtC_Name->Text ="";
    edtC_Sex->Text ="";
    edtC_Tel->Text ="";
    
    // �л�ListView����ʾ���Ϊ��ϸ��Ϣ
    ListView1->ViewStyle = vsReport;
 
    // ���ListView�����к��е�����
    ListView1->Columns->Clear();
    
    // ���ⴴ��
    ListTitleCreat();
}
//---------------------------------------------------------------------------

void TForm1::ShowData(){

    // ���ݱ�ʾ
    customer->Open();
    edtC_Id->Text=customer->FieldValues["C_ID"];
    edtC_Name->Text=customer->FieldValues["C_NAME"];
    edtC_Sex->Text=customer->FieldValues["C_SEX"];
    edtC_Tel->Text=customer->FieldValues["C_TEL"];
}
//---------------------------------------------------------------------------

void TForm1::ListTitleCreat(){
    // ��ӵ�һ��
    TListColumn *lc = ListView1->Columns->Add();
    lc->Caption = "Ա������";
    lc->Width = 120;
 
    // ��ӵڶ���
    lc = ListView1->Columns->Add();
    lc->Caption = "Ա������";
    lc->Width = 125;
 
    // ��ӵ�����
    lc = ListView1->Columns->Add();
    lc->Caption = "Ա���Ա�";
    lc->Width = 125;

    // ��ӵ�����
    lc = ListView1->Columns->Add();
    lc->Caption = "Ա���绰";
    lc->Width = 130;
}
//---------------------------------------------------------------------------

void TForm1::ListDataShow(){
    // ��ť���ʱ�������
    ListView1->Items->Clear();
    // ��ֹ�û�ֱ���޸Ľڵ�ı���
    ListView1->ReadOnly=true;
    customer->Close();
    customer->Open();
    // �������
    while(!customer->Eof){
        TListItem *li = ListView1->Items->Add();
        li->Caption = customer->FieldValues["C_ID"];
        li->SubItems->Add(customer->FieldValues["C_NAME"]);
        li->SubItems->Add(customer->FieldValues["C_SEX"]);
        li->SubItems->Add(customer->FieldValues["C_TEL"]);
        customer->Next();
    }
    
    // �����ָ���ƶ����ڵ���ʱ���ı�������ɫΪ��ɫ
    ListView1->HotTrack=true;
    // ��������ѡ��
    ListView1->RowSelect = true;
    // ����ָ�����д���ѡ��״̬���кŴ�0��ʼ
    // ListView1->Items->Item[0]->Selected=True;
    // ��ý���
    // ListView1->SetFocus();
    customer->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnFristClick(TObject *Sender)
{
    customer->Close();
    customer->Open();
    customer->First();
    // �ı������ݱ�ʾ
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
    if(MessageBox(NULL,"ȷ����Ϣ����","ȷ��",33)==IDOK){
        customer->Edit();
        customer->FieldValues["C_ID"]=edtC_Id->Text;
        customer->FieldValues["C_NAME"]=edtC_Name->Text;
        customer->FieldValues["C_SEX"]=edtC_Sex->Text;
        customer->FieldValues["C_TEL"]=edtC_Tel->Text;
        customer->Post();
        ShowData();
        BtnChange->Caption="�޸�";
        ListDataShow();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnDeleteClick(TObject *Sender)
{
    if(MessageBox(NULL,"ȷ��ɾ��","����",49)==IDOK){
        customer->Open();
        customer->Delete();
        ListDataShow();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnAddClick(TObject *Sender)
{
    customer->Open();
    ShowMessage("����������뵥����ȷ�ϡ���ť����DB");
    // text�ı������ݳ�ʼ��
    edtC_Id->Text ="";
    edtC_Name->Text ="";
    edtC_Sex->Text ="";
    edtC_Tel->Text ="";
    BtnChange->Caption="ȷ��";
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
    // �ı������ݱ�ʾ
    ShowData();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnSelectClick(TObject *Sender)
{
    // ȡ��ѡ�нڵ���ı�
    if(ListView1->Selected != NULL){
        // ȡ��ѡ���е��к�
        int i =ListView1->Selected->Index;
        edtC_Id->Text = ListView1->Selected->Caption;
        edtC_Name->Text = ListView1->Items->Item[i]->SubItems->Strings[0];
        edtC_Sex->Text = ListView1->Items->Item[i]->SubItems->Strings[1];
        edtC_Tel->Text = ListView1->Items->Item[i]->SubItems->Strings[2];
        customer->Open();
        customer->MoveBy(i);
        
    } else {
         ShowMessage("û��ѡ���κ����ݣ���ȷ�ϣ�");
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

