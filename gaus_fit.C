// gaus_fit.C 任务3：生成随机数，直方图高斯拟合
void gaus_fit()
{
    // 1.新建直方图
    TH1F *h1 = new TH1F("h1","Gaussian random data;x;Counts",100,0,200);

    //2.随机数发生器
    TRandom3 rnd(1234); //设置随机种子

    //循环产生10000个服从高斯分布的随机数，均值100，sigma=10
    for(int i=0;i<10000;i++){
        double x = rnd.Gaus(100,10);
        h1->Fill(x);
    }

    //3.画布
    TCanvas *c1 = new TCanvas("c1","canvas",800,600);

    //4.做高斯拟合
    h1->Fit("gaus");
    h1->Draw();

    //保存图片
    c1->SaveAs("gaus_result.png");
}
