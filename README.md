# ROOT与高能物理数据分析基础
## 项目简介
本项目是高能物理数据分析入门训练，基于ROOT框架完成，共5项任务，在WSL2 Ubuntu环境下开发。

## 环境依赖
- WSL2 Ubuntu
- C++编译器(g++)
- Python
- ROOT

## 文件说明
- gaus_fit.C：生成高斯随机数据，绘制直方图并高斯拟合（任务3）
- tree_write.C：创建ROOT文件，构造TTree，生成1000组粒子动量数据存入TTree（任务4写）
- tree_read.C：读取ROOT文件的TTree，提取px动量，绘制直方图（任务4读）
- invariant_mass.C：读取TTree粒子动量，两两配对，重建双粒子不变质量并绘图（任务5）
- data.root：生成的ROOT数据文件
- *.png：程序输出的直方图图片

## 复现方法
1. 在WSL2 Ubuntu安装ROOT
2. 克隆本仓库
3. 依次运行：
root gaus_fit.C
root tree_write.C
root tree_read.C
root invariant_mass.C
4. 运行完成后，在目录下查看生成的png图片。

## 训练总结
本训练学习ROOT的基础绘图、TTree数据存储与读取、双粒子不变质量重建，模拟高能物理实验数据分析流程。
