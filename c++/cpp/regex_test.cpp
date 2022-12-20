// g++ -o regex_test regex_test.cpp
// ref : https://modoocode.com/303

#include <iostream>
#include <regex>
#include <vector>

using namespace std;
 
void match_test();
void match_test2();
void search_test();
void search_test2();
void replace_test();
void replace_test2();

// *************************************
int main() 
{
    //match_test();
    //match_test2();
    //search_test();
    //search_test2();
    //replace_test();
    replace_test2();
}

// *************************************
void match_test()
{
    vector<string> phone_numbers = 
        {"010-1234-5678", "010-123-4567", "011-1234-5567", "010-12345-6789", "123-4567-8901", "010-1234-567"};

    regex re("[01]{3}-\\d{3,4}-\\d{4}");
    for (const auto &number : phone_numbers) 
        std::cout << number << ": " << std::boolalpha << std::regex_match(number, re) << '\n';
}

// *************************************
void match_test2()
{
    vector<string> phone_numbers = 
        {"010-1234-5678", "010-123-4567", "011-1234-5567", "010-12345-6789", "123-4567-8901", "010-1234-567"};

    regex re("[01]{3}-(\\d{3,4})-\\d{4}");
    smatch match;  // 매칭된 결과를 string 으로 보관
    for (const auto &number : phone_numbers) 
    {
        if (std::regex_match(number, match, re)) 
        {
            for (size_t i = 0; i < match.size(); i++)
                std::cout << "Match : " << match[i].str() << std::endl;

            cout << "-----------------------\n";
        }
    }
}

// *************************************
void search_test()
{
    string html = R"(
        <div class="social-login">
          <div class="small-comment">다음으로 로그인 </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            또는 직접 입력하세요 (댓글 수정시 비밀번호가 필요합니다)
          </div>
          <input name="name" id="name" placeholder="이름">
          <input name="password" id="password" type="password" placeholder="비밀번호">
        </div>
        <div id="adding-comment" class="sk-fading-circle">
          <div class="sk-circle1 sk-circle">a</div>
          <div class="sk-circle2 sk-circle">b</div>
          <div class="sk-circle3 sk-circle">asd</div>
          <div class="sk-circle4 sk-circle">asdfasf</div>
          <div class="sk-circle5 sk-circle">123</div>
          <div class="sk-circle6 sk-circle">aax</div>
          <div class="sk-circle7 sk-circle">sxz</div>
        </div>
    )";

    regex re(R"(<div class="sk[\w -]*">\w*</div>)");
    smatch match;
    while (regex_search(html, match, re)) 
    {
        cout << match.str() << '\n';
        html = match.suffix();
    }
}

// *************************************
void search_test2()
{
    string html = R"(
        <div class="social-login">
          <div class="small-comment">다음으로 로그인 </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            또는 직접 입력하세요 (댓글 수정시 비밀번호가 필요합니다)
          </div>
          <input name="name" id="name" placeholder="이름">
          <input name="password" id="password" type="password" placeholder="비밀번호">
        </div>
        <div id="adding-comment" class="sk-fading-circle">
          <div class="sk-circle1 sk-circle">a</div>
          <div class="sk-circle2 sk-circle">b</div>
          <div class="sk-circle3 sk-circle">asd</div>
          <div class="sk-circle4 sk-circle">asdfasf</div>
          <div class="sk-circle5 sk-circle">123</div>
          <div class="sk-circle6 sk-circle">aax</div>
          <div class="sk-circle7 sk-circle">sxz</div>
        </div>
    )";

    regex re(R"(<div class="sk[\w -]*">\w*</div>)");
    smatch match;

    auto start = sregex_iterator(html.begin(), html.end(), re);
    auto end = sregex_iterator();

    while (start != end) 
    {
        cout << start->str() << endl;
        ++start;
    }
}

// *************************************
void replace_test()
{
    string html = R"(
        <div class="social-login">
          <div class="small-comment">다음으로 로그인 </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            또는 직접 입력하세요 (댓글 수정시 비밀번호가 필요합니다)
          </div>
          <input name="name" id="name" placeholder="이름">
          <input name="password" id="password" type="password" placeholder="비밀번호">
        </div>
        <div id="adding-comment" class="sk-fading-circle">
          <div class="sk-circle1 sk-circle">a</div>
          <div class="sk-circle2 sk-circle">b</div>
          <div class="sk-circle3 sk-circle">asd</div>
          <div class="sk-circle4 sk-circle">asdfasf</div>
          <div class="sk-circle5 sk-circle">123</div>
          <div class="sk-circle6 sk-circle">aax</div>
          <div class="sk-circle7 sk-circle">sxz</div>
        </div>
    )";

    regex re(R"r(sk-circle(\d))r");
    smatch match;

    string modified_html = std::regex_replace(html, re, "$1-sk-circle");
    cout << modified_html;
}

// *************************************
void replace_test2()
{
    string html = R"(
        <div class="social-login">
          <div class="small-comment">다음으로 로그인 </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            또는 직접 입력하세요 (댓글 수정시 비밀번호가 필요합니다)
          </div>
          <input name="name" id="name" placeholder="이름">
          <input name="password" id="password" type="password" placeholder="비밀번호">
        </div>
        <div id="adding-comment" class="sk-fading-circle">
          <div class="sk-circle1 sk-circle">a</div>
          <div class="sk-circle2 sk-circle">b</div>
          <div class="sk-circle3 sk-circle">asd</div>
          <div class="sk-circle4 sk-circle">asdfasf</div>
          <div class="sk-circle5 sk-circle">123</div>
          <div class="sk-circle6 sk-circle">aax</div>
          <div class="sk-circle7 sk-circle">sxz</div>
        </div>
    )";

    regex re(R"r((sk-circle(\d) sk-circle))r");
    smatch match;

    string modified_html = std::regex_replace(html, re, "$2-sk-circle");
    cout << modified_html;
}

