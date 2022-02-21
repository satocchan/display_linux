#include<opencv2/opencv.hpp>
#include<string>
#include<iostream>
#include<fstream>
#include<array>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<random>
#include<algorithm>
#include<chrono>
#include<thread>
#include<mutex>


class Image
{
    private:
        int size;
        int fontScale;
        std::string image_text;
        cv::Mat img;
        int index;

    public:
        Image(int fontScale, std::string image_text, cv::Mat img, int size, int index) : 
        fontScale(fontScale), image_text(image_text), img(img), size(size), index(index){}

        cv::Mat image_getter()
        {
            return img;
        }

        std::string text_getter()
        {
            return image_text;
        }

        int fontscale_getter()
        {
            return fontScale;
        }

        int size_getter()
        {
            return size;
        }

        int index_getter()
        {
            return index;
        }
};



void save(std::string filename, std::vector<int>size, std::vector<int>index, std::vector<int> fontscale, std::vector<std::string> output,
          std::vector<std::string> input, std::vector<double> time)
{
    std::fstream fileout;
    fileout.open(filename, std::ios_base::out);
    if(!fileout.is_open())
    {
        std::cout << "failed to open" << "\n";
    }
    else
    {
        for(size_t i = 0; i < time.size(); i++)
        {
            fileout << size.at(i) << "," << fontscale.at(i) << "," << index.at(i) << "," << time.at(i) << "," << output.at(i)<< "," << input.at(i) << std::endl;
        }
    }
}


int main (int argc, char **argv)
{ 
    std::string name = "user";
    if(argc == 2)
    {
        name = std::string(argv[1]);
    }
    else
    {
        std::cout << "名前を入力してください" << std::endl;
        return 1;
    }

    std::array<std::string, 20> text1 = {"CHK", "IIE", "LDX", "DBR", "NIP",
                                         "DIG", "RPL", "MAB", "CTZ", "WDH",
                                         "PFR", "BPC", "GAD", "DDC", "SSL",
                                         "HXX", "PKM", "AAK", "CAF", "ZSI"};

    std::array<std::string, 20> text2 = {"ZKS", "BAN", "NMA", "NYE", "HKZ",
                                         "WIK", "CFT", "NIY", "BRC", "ZEF",
                                         "MDP", "DEP", "TWB", "TGX", "XPH",
                                         "WKP", "DMX", "YGG", "WCX", "YZB"};
    
    std::array<std::string, 20> text3 = {"ARN", "IZK", "DEA", "XFL", "WFE",
                                         "TYN", "YTL", "BXN", "XTM", "FNF",
                                         "EMW", "TWW", "EXY", "CSE", "NMH",
                                         "REF", "FAY", "RCW", "DZN", "SDC"};
    
    std::array<std::string, 20> text4 = {"BBS", "LMD", "SCN", "DPD", "RES",
                                         "SGK", "HWA", "HRK", "ZFE", "FEZ",
                                         "NFY", "HRK", "IGK", "XKB", "ABD",
                                         "STK", "BCE", "ZKX", "IKA", "MNE"};
    
    std::array<std::string, 20> text5 = {"KFA", "ZIB", "AFH", "EPI", "GTW",
                                         "BII", "BZW", "LTH", "MAD", "AMI",
                                         "KZR", "KYZ", "LWF", "SZT", "CFK",
                                         "YFW", "FGW", "BTL", "GGK", "IEZ"};
    
    std::array<std::string, 20> text6 = {"EMW", "ZTE", "LXM", "ASD", "NWP",
                                         "INE", "DMN", "HFA", "ABT", "RSI",
                                         "RZZ", "TYS", "XGL", "KEC", "NTY",
                                         "EDK", "HEZ", "YKC", "XLE", "MBY"};

    std::array<std::string, 20> text7 = {"EZM", "KPP", "AWF", "BFG", "YWH",
                                         "BLD", "ANL", "BCB", "SHT", "CAH",
                                         "FCH", "RKX", "GLR", "KKW", "PFM",
                                         "AGB", "BHM", "KGM", "IZX", "DBW"};
    
    std::array<std::string, 20> text8 = {"MKW", "LIW", "GDD", "IEY", "IHX",
                                         "BNN", "YIP", "MYC", "IAG", "LRH",
                                         "DCT", "XNC", "PDX", "TFG", "PMP",
                                         "IPC", "ZKM", "LXK", "PFI", "YPZ"};

    std::array<std::string, 20> text9 = {"HHS", "KDD", "HSE", "SIA", "EFI",
                                         "WWN", "SEM", "YYB", "SDG", "PSI",
                                         "XZR", "NIS", "PPK", "XHS", "TNX",
                                         "BGN", "MAT", "BZN", "ANS", "HDK"};

    std::array<std::array<std::string, 20>, 8> all_text_30 = {text1, text2, text3, text4,
                                                              text5, text6, text7, text8};

    std::array<std::array<std::string, 20>, 8> all_text_40 = {text8, text7, text6, text5,
                                                              text4, text3, text2, text1};

    std::array<std::array<std::string, 20>, 8> all_text_50 = {text4, text3, text2, text1,
                                                              text8, text7, text6, text5};
    std::vector<cv::Mat> all_image;

    std::string date = "20211203";
    int size1 = 30;
    int size_counter1 = 1;
    int font_counter1 = 5;
    int text_counter1 = 1;
    for (int i = 0; i < 480; i++)
    {
        if (size_counter1 == 161)
        {
            size1 = 40;
            font_counter1 = 5;
        }
        else if (size_counter1 == 321)
        {
            size1 = 50;
            font_counter1 = 5;
        }
        std::string file_name = "./" + date + "image/" + date + "size" + std::to_string(size1) + "/size" + std::to_string(size1) +
                                "-font" + std::to_string(font_counter1) + "-" + std::to_string(text_counter1) +
                                ".jpg";

        cv::Mat read_img = cv::imread(file_name);
        if (read_img.empty() == true) 
        {
	        return 2;
        }

        all_image.push_back(read_img);
        if (text_counter1 == 20)
        {
            text_counter1 = 0;
            font_counter1 += 2;
        }
        text_counter1++;
        size_counter1++;
    }

    std::vector<Image> all_image_information;
    std::array<std::array<std::string, 20>, 8> all_text = all_text_30;
    int size2 = 30;
    int font_counter2 = 5;
    int text_counter2 = 1;
    int img_counter2 = 0;
    for (int k = 0; k < 3; k++)
    {
        if (k == 1)
        {
            font_counter2 = 5;
            size2 = 40;
            all_text = all_text_40;
        }
        else if (k == 2)
        {
            font_counter2 = 5;
            size2 = 50;
            all_text = all_text_50;
        }

        for (size_t i = 0; i < all_text.size(); i++)
        {
            for (size_t j = 0; j < all_text[i].size(); j++)
            {
                Image img_information(font_counter2, all_text[i][j], all_image.at(j + 20*img_counter2), size2, text_counter2);
                all_image_information.push_back(img_information);
                if (text_counter2 == 20)
                {
                    text_counter2 = 0;
                    font_counter2 += 2;
                }
                text_counter2++;
            }
            img_counter2++;
        }
    }
  
    std::srand(time(NULL));
    std::mt19937 engine(rand());
    std::shuffle(all_image_information.begin(), all_image_information.end(), engine);

    std::vector<int> size;
    std::vector<int> index;
    std::vector<int> fontscale;
    std::vector<std::string> output;
    std::vector<std::string> input;
    std::vector<double> time_result;

    cv::Mat black_image = cv::Mat::zeros(1080, 1920, CV_8UC3);
    cv::Mat red_image(1080, 1920, CV_8UC3, cv::Scalar(0, 0, 255));
    cv::namedWindow("Example", cv::WINDOW_AUTOSIZE);
    cv::moveWindow("Example", 1920, 0);
    cv::imshow("Example", black_image);
    cv::waitKey(1000);

    char c1;
    do
    {
        std::cout << "実験を開始するのでスペースを押したあとエンターを押してください" << std::endl;
        c1 = std::cin.get();
    }
    while(c1 != ' ');

    int counter = 0;
    for(size_t i = 0; i < all_image_information.size(); i++)
    {
        if((counter % 100 == 0) && (counter != 0))
        {
            cv::imshow("Example", red_image);
            cv::waitKey(1000);
            char c3;
            do
            {
                std::cout << "実験を開始するのでスペースを押したあとエンターを押してください" << std::endl;
                c3 = std::cin.get();
            }
            while(c3 != ' ');
        }
        counter++;
        char c2;
        std::string answer;
        std::chrono::system_clock::time_point start, end;

        int wait_s = rand() % 5;
        std::this_thread::sleep_for(std::chrono::seconds(wait_s));
        
        cv::imshow("Example", all_image_information.at(i).image_getter());
        cv::waitKey(1000);

        start = std::chrono::system_clock::now();
        do
        {
            std::cout << "スペースを押したあとエンターを押してください" << std::endl;
            c2 = std::cin.get();
        }
        while(c2 != ' ');      
        end = std::chrono::system_clock::now();

        std::cout << "読み取った文字を入力してください" << std::endl;
        cv::imshow("Example", black_image);
        cv::waitKey(1000);
    
        std::cin >> answer;
        while(answer.length() != 3)
        {
            std::cout << "3文字で入力してください" << std::endl;
            std::cin >> answer;
        }
        double diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "time: " << diff << "ms\n"
                  << "cont: " << counter << "\n"
                  << "size: " << all_image_information.at(i).fontscale_getter() << "\n" << std::endl;

        size.push_back(all_image_information.at(i).size_getter());
        index.push_back(all_image_information.at(i).index_getter());
        fontscale.push_back(all_image_information.at(i).fontscale_getter());
        output.push_back(all_image_information.at(i).text_getter());
        input.push_back(answer);
        time_result.push_back(diff);
        
    }

    cv::destroyWindow("Example");

    save(name + ".csv", size, index, fontscale, output, input, time_result);

    return 0;
} 