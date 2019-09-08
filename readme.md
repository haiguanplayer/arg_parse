# a argparse

Make a Parser，support add argument(positional, optional), subparses, etc.


需求分析：
创建（主）解析器 ArgumentParser 对象
    功能：
        1.add_argument() 添加参数（positional, optional）

        2.print_help() 返回帮助信息

        3.传入无效参数进行报错

        4.parse_args() 解析输入的参数（只有主 parser 包含）

        5.add_subparsers() 返回子命令解析对象
            功能：
                add_parser() 添加子解析器（支持功能 1、2、3），多个子解析器互斥
                set_defaults() 
        

