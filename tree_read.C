// tree_read.C 任务4：读取data.root的TTree，画px分布
void tree_read()
{
    // 只读打开root文件
    TFile *f = new TFile("data.root","READ");

    // 取出TTree
    TTree *tree = (TTree*)f->Get("myTree");

    double px, py, pz;
    tree->SetBranchAddress("px",&px);
    tree->SetBranchAddress("py",&py);
    tree->SetBranchAddress("pz",&pz);

    // 直方图：100个bin，x轴范围0~20
    TH1F *h_px = new TH1F("h_px","distribution of px;px;Counts",100,0,20);

    // 获取总事例数
    int nEntries = tree->GetEntries();
    cout << "总事例数：" << nEntries << endl;

    for(int i=0; i<nEntries; i++)
    {
        tree->GetEntry(i);
        h_px->Fill(px);
    }

    TCanvas *c2 = new TCanvas("c2","canvas2",800,600);
    h_px->Draw();
    gPad->Update();
    c2->SaveAs("px_hist.png");

    f->Close();
}

