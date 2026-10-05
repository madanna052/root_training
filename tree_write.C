// tree_write.C 任务4：写入TTree，生成root数据文件
void tree_write()
{
    // 创建ROOT文件，"RECREATE"意思：新建，有同名文件就覆盖
    TFile *f = new TFile("data.root","RECREATE");

    // 创建TTree，名字myTree，标题"example tree"
    TTree *tree = new TTree("myTree","example tree");

    // 定义变量，存粒子信息
    double px, py, pz;

    // 创建分支Branch，把变量绑定到tree上
    tree->Branch("px",&px,"px/D");
    tree->Branch("py",&py,"py/D");
    tree->Branch("pz",&pz,"pz/D");
    // /D 代表double（小数类型）

    // 随机数
    TRandom3 rnd(4321);

    // 循环生成1000组数据，填充进tree
    for(int i=0;i<1000;i++){
        px = rnd.Gaus(10,2);
        py = rnd.Gaus(5,1);
        pz = rnd.Gaus(20,3);
        tree->Fill(); // 把这一组px,py,pz存入tree
    }

    tree->Write(); //把tree写入data.root文件
    f->Close();    //关闭文件
}
