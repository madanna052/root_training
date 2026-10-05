// invariant_mass.C 任务5：双粒子不变质量重建
void invariant_mass()
{
    // 只读打开ROOT数据文件
    TFile *f = new TFile("data.root","READ");
    // 获取TTree
    TTree *tree = (TTree*)f->Get("myTree");

    // 定义动量变量，绑定TTree的三个分支
    double px, py, pz;
    tree->SetBranchAddress("px",&px);
    tree->SetBranchAddress("py",&py);
    tree->SetBranchAddress("pz",&pz);

    // 直方图：横坐标0~40，容纳全部不变质量
    TH1F *h_mass = new TH1F("h_mass","Invariant Mass;M;Counts",100,0,40);

    int nEntries = tree->GetEntries();

    // 两两配对循环
    for(int i=0; i < nEntries-1; i += 2)
    {
        // 读取第i个粒子
        tree->GetEntry(i);
        double p1x = px;
        double p1y = py;
        double p1z = pz;
        double E1 = sqrt(p1x*p1x + p1y*p1y + p1z*p1z);

        // 读取配对的下一个粒子
        tree->GetEntry(i+1);
        double p2x = px;
        double p2y = py;
        double p2z = pz;
        double E2 = sqrt(p2x*p2x + p2y*p2y + p2z*p2z);

        // 系统总能量、总动量分量
        double E_total = E1 + E2;
        double px_total = p1x + p2x;
        double py_total = p1y + p2y;
        double pz_total = p1z + p2z;

        // 不变质量公式
        double M_sq = E_total*E_total - (px_total*px_total + py_total*py_total + pz_total*pz_total);
        if(M_sq < 0) continue; // 规避负数开根号，跳过无效事例
        double M = sqrt(M_sq);

        h_mass->Fill(M);
    }

    // 绘图并保存图片
    TCanvas *c_m = new TCanvas("c_m","mass canvas",800,600);
    h_mass->Draw();
    gPad->Update();
    c_m->SaveAs("invariant_mass.png");

    // 关闭文件
    f->Close();
}

