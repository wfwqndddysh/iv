"------------------------------------------------------------------------------
" YCM配置
"missit add for vundle
set nocompatible              " be iMproved, required
filetype on" required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

" let Vundle manage Vundle, required
Plugin 'gmarik/Vundle.vim'

" ycm
Plugin 'Valloric/YouCompleteMe'

" nerdtree
Plugin 'scrooloose/nerdtree'

" easymotion
Plugin 'Lokaltog/vim-easymotion'

" stl syntax
Plugin 'Mizuchi/STL-Syntax'

" tagbar
Plugin 'majutsushi/tagbar'

" ctrlsf
Plugin 'dyng/ctrlsf.vim'

" nerdcommenter
Plugin 'scrooloose/nerdcommenter'

" ultisnips
Plugin 'SirVer/ultisnips'

" minibufexpl
" Plugin 'fholgado/minibufexpl.vim'

" indentLine
Plugin 'Yggdroot/indentLine'

" ctrlp
Plugin 'kien/ctrlp.vim'

" ListToogle
Plugin 'Valloric/ListToggle'

" airline
Plugin 'bling/vim-airline'

" Solarized
Plugin 'altercation/vim-colors-solarized'

" vim-expand-region
Plugin 'terryma/vim-expand-region'

" rainbow
Plugin 'luochen1990/rainbow'

" cmdline-completion
Plugin 'vim-scripts/cmdline-completion'



" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
" Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
" Plugin 'L9'
" Git plugin not hosted on GitHub
" Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
" Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
" Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Avoid a name conflict with L9
" Plugin 'user/L9', {'name': 'newL9'}

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line


"let g:ycm_global_ycm_extra_conf='/home/missit/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
let g:syntastic_error_symbol='✗'
let g:syntastic_warning_symbol='⚠'
let g:ycm_confirm_extra_conf = 0

" 加载ycm_extra_conf.py时不进行确认
"let g:ycm_global_ycm_extra_conf.py=0;
" 带开syntastic插件的语法check功能，好像是禁止了ycm的部分check功能，这个需要比
" 较哪个更好用之后在决定用哪个
" let g:ycm_show_diagnostics_ui=0
"
" 查看错误的两种方式：一种是将光标移至问题行，vim 将在其底部显示简要错误描述
" 一种是将光标移至问题行，键入 <leader>d 后，vim 将在其底部显示详细错误描述。
"------------------------------------------------------------------------------


"------------------------------------------------------------------------------
" indexer 插件，自动更新tags
" 设置插件 indexer 调用 ctags 的参数
" 默认 --c++-kinds=+p+l，重新设置为 --c++-kinds=+p+l+x+c+d+e+f+g+m+n+s+t+u+v
" 默认 --fields=+iaS 不满足 YCM 要求，需改为 --fields=+iaSl
"let g:indexer_ctagsCommandLineOptions="--c++-kinds=+p+l+x+c+d+e+f+g+m+n+s+t+u+v --fields=+iaSl --extra=+q"
"------------------------------------------------------------------------------


"------------------------------------------------------------------------------
" " tagbar 配置
" " 设置 tagbar 子窗口的位置出现在主编辑区的左边
" let tagbar_left=1
" " 设置显示／隐藏标签列表子窗口的快捷键。速记：tag list 
" nnoremap <Leader>tl :TagbarToggle<CR> 
" " 设置标签子窗口的宽度 
" let tagbar_width=32 
" " tagbar 子窗口中不显示冗余帮助信息 
" let g:tagbar_compact=1
" " 设置 ctags 对哪些代码元素生成标签
" let g:tagbar_type_cpp = {
"     \ 'kinds' : [
"         \ 'd:macros:1',
"         \ 'g:enums',
"         \ 't:typedefs:0:0',
"         \ 'e:enumerators:0:0',
"         \ 'n:namespaces',
"         \ 'c:classes',
"         \ 's:structs',
"         \ 'u:unions',
"         \ 'f:functions',
"         \ 'm:members:0:0',
"         \ 'v:global:0:0',
"         \ 'x:external:0:0',
"         \ 'l:local:0:0'
"      \ ],
"      \ 'sro'        : '::',
"      \ 'kind2scope' : {
"          \ 'g' : 'enum',
"          \ 'n' : 'namespace',
"          \ 'c' : 'class',
"          \ 's' : 'struct',
"          \ 'u' : 'union'
"      \ },
"      \ 'scope2kind' : {
"          \ 'enum'      : 'g',
"          \ 'namespace' : 'n',
"          \ 'class'     : 'c',
"          \ 'struct'    : 's',
"          \ 'union'     : 'u'
"      \ }
" \ }
"------------------------------------------------------------------------------






"------------------------------------------------------------------------------
" indentLine 配置
let g:indentLine_enabled = 0



"------------------------------------------------------------------------------
" 语法高亮, 搜索高亮
set hlsearch
" 开启语法高亮功能
syntax enable
" 允许用指定语法高亮配色方案替换默认方案
syntax on
"colorscheme desert
let g:solarized_underline = 0
let g:solarized_termtrans = 1
let g:solarized_visibility = "normal"
let g:solarized_bold = 0
let g:solarized_termcolors=256
set background=dark
colorscheme solarized
"------------------------------------------------------------------------------






"------------------------------------------------------------------------------
" 光标，状态栏，行号, 换行......
" 总是显示状态栏
set laststatus=2
" 显示光标当前位置
set ruler
" 开启行号显示
set number
" 高亮显示当前行
" set cursorline
" 高亮显示当前列
" set cursorcolumn
set colorcolumn=80
" 常行是否换行显示长行
set nowrap
"在状态栏显示正在输入的命令
set showcmd
"------------------------------------------------------------------------------





"------------------------------------------------------------------------------
" 缩进, tab
" 自动适应不用语言的智能缩进
set autoindent
filetype plugin indent on
" 设置编辑时制表符占用空格数
set tabstop=4
" 设置格式化时制表符占用空格数
set shiftwidth=4
" 让vim把连续数量的空格视为一个制表符
set softtabstop=4
" tab扩展我空格
set expandtab
"retab 命令将文件按上述设置进行缩进去
"------------------------------------------------------------------------------






"------------------------------------------------------------------------------
" 折叠, 基于标记，缩进，语法
" 按语法折叠
set foldmethod=syntax
"set foldmethod=indent
"for json"
"set foldmethod=marker
"set foldmarker={,}
"关闭折叠
"set nofoldenable
"------------------------------------------------------------------------------







"------------------------------------------------------------------------------
" 设置用于gf命令时的路径，在一些工程里非常方便的查看其他头文件，虽然其他的
" 的插件有更精确的语言分析，但是gf打开一看，总是有好处的
" let &path.="src/include,/usr/include/AL,"
"------------------------------------------------------------------------------
 
 




"------------------------------------------------------------------------------
" 设置makeprg变量，这样可以在非常方便的在任何地方make，不用每次都传路经和选项
" 由于该命令常用，所以非常能提高生产力
" set makeprg=make\ -C\ ../build\ -j9
 
 




"------------------------------------------------------------------------------
" NERDTree基本配置
" 在 vim 启动的时候默认开启 NERDTree（autocmd 可以缩写为 au）
" autocmd VimEnter * NERDTree
" 按下 F2 调出/隐藏 NERDTree
map  :silent! NERDTreeToggle
" 将 NERDTree 的窗口设置在 vim 窗口的右侧（默认为左侧）
let NERDTreeWinPos="right"
" 当打开 NERDTree 窗口时，自动显示 Bookmarks
let NERDTreeShowBookmarks=1
"------------------------------------------------------------------------------





"------------------------------------------------------------------------------
let g:EasyMotion_do_mapping = 0 " Disable default mappings
" Bi-directional find motion
" Jump to anywhere you want with minimal keystrokes, with just one key
" binding.
" `s{char}{label}`
nmap s <Plug>(easymotion-s)
" or
" `s{char}{char}{label}`
" Need one more keystroke, but on average, it may be more comfortable.
nmap s <Plug>(easymotion-s2)

" Turn on case insensitive feature
let g:EasyMotion_smartcase = 1

" JK motions: Line motions
map <Leader>j <Plug>(easymotion-j)
map <Leader>k <Plug>(easymotion-k)
"------------------------------------------------------------------------------













"------------------------------------------------------------------------------
"下面是一些平时用的命令使用方法，先做个记录，以后可以直接在这里实践练习
" 1. vim的几种模式和按键映射
" 
" 转载自：【1】
" 
" Map是Vim强大的一个重要原因，可以自定义各种快捷键，用起来自然得心应手。
" vim里最基本的map用法也就是
" 
" :map c a
" 这里把c映射成了a，在map生效的情况下，按下c就等同于按下了a
" 当然，常用的Ctrl,Shift,Alt自然也是支持的。
" 
" 令Ctrl+a对应到a
" :map <C-a> a
" 令Alt+a对应到a
" :map <A-a> a
" 令Ctrl+Alt+a对应到a
" :map <C-A-a> a
" 到此，我们已经可以做很多事情了。
" 但是map命令远不只这一种，在不同的模式下，同一组按键可以被映射到不同的组合上。
" Vim的模式众多，但是一般被提及的也就是这么几种:
" 
" Normal Mode
" 也就是最一般的普通模式，默认进入vim之后，处于这种模式。
" 
" Visual Mode
" 一般译作可视模式，在这种模式下选定一些字符、行、多列。
" 在普通模式下，可以按v进入。
" 
" Insert Mode
" 插入模式，其实就是指处在编辑输入的状态。普通模式下，可以按i进入。
" 
" Select Mode
" 在gvim下常用的模式，可以叫作选择模式吧。用鼠标拖选区域的时候，就进入了选择模式。
" 和可视模式不同的是，在这个模式下，选择完了高亮区域后，敲任何按键就直接输入并替换选择的文本了。
" 和windows下的编辑器选定编辑的效果一致。普通模式下，可以按gh进入。
" 
" Command-Line/Ex Mode
" 就叫命令行模式和Ex模式吧。两者略有不同，普通模式下按冒号(:)进入Command-Line模式，可以输入各种命令，
" 使用vim的各种强大功能。普通模式下按Q进入Ex模式，其实就是多行的Command-Line模式。
" 
" 对于Map，有几个基本的概念
" 
" 命令的组合
" 同Vim下的其他命令一样，命令的名字往往由好几段组成。前缀作为命令本身的修饰符，微调命令的效果。
" 对于map而言，可能有这么几种前缀
" 
" nore
" 表示非递归，见下面的介绍
" 
" n
" 表示在普通模式下生效
" 
" v
" 表示在可视模式下生效
" 
" i
" 表示在插入模式下生效
" 
" c
" 表示在命令行模式下生效
" 
" Recursive Mapping
" 递归的映射。其实很好理解，也就是如果键a被映射成了b，c又被映射成了a，如果映射是递归的，那么c就被映射成了b。
" 
" :map a b
" :map c a
" 对于c效果等同于
" 
" :map c b
" 默认的map就是递归的。如果遇到[nore]这种前缀，比如:noremap，就表示这种map是非递归的。
" 
" unmap
" unmap后面跟着一个按键组合，表示删除这个映射。
" 
" :unmap c
" 那么在map生效模式下，c不再被映射到a上。
" 
" 同样，unmap可以加各种前缀，表示影响到的模式。
" 
" mapclear
" mapclear直接清除相关模式下的所有映射。
" 同样，mapclear可以加各种前缀，表示影响到的模式。
" 
" 这里列出常用的一些map命令，默认map命令影响到普通模式和可视模式。
" 
" :map :noremap :unmap :mapclear
" :nmap :nnoremap :nunmap :nmapclear
" :vmap :vnoremap :vunmap :vmapclear
" :imap :inoremap :iunmap :imapclear
" :cmap :cnoremap :cunmap :cmapclear
" 
" 可以试试这些命令
" 
" 命令行模式下建一个mapping
" nmap b a
" 现在普通模式下，按b，可以进入插入模式，随便输入一些字符
" 命令行模式下建一个mapping
" vmap b d
" 现在普通模式下，按V，进入了可视模式，并且选定了一整行，按下b，可以删除整行
" 命令行模式下建一个mapping
" imap b a
" 现在试着给正在编辑的这个文件输入一个字符”b”吧 :p
" 命令行模式下建一个mapping
" cmap b c
" 命令行模式下， 按下b，会出来一个a
" 好了，到此vim的按键已经被你弄得乱七八糟了，试着用unmap和mapclear清除这些mapping吧。:]

"------------------------------------------------------------------------------
" 5. vim自动缩进的几种方式
" There are a number of methods enabling automatic indentation in Vim, ranging from fairly "stupid" and unintrusive ones, like 'autoindent' and 'smartindent', to complex ones such as 'cindent' and custom indentation based on filetype using 'indentexpr'. The amount of indentation used for one level is controlled by the 'shiftwidth' option（缩进的个数是由'shiftwidth'设置来控制的）.【1】
" 
" 'autoindent'
" 'autoindent' does nothing more than copy the indentation from the previous line, when starting a new line. It can be useful for structured text files, or when you want to control most of the indentation manually, without Vim interfering.
" 
" 'autoindent' does not interfere with other indentation settings, and some file type based indentation scripts even enable it automatically.（一些基于filetype来缩进的脚本会自动enable它，所以set autoindent 加上filetype plugin indent on是一个比较好的选择）
" 
" 'smartindent' and 'cindent'
" 
" 'smartindent' automatically inserts one extra level of indentation in some cases, and works for C-like files. 'cindent' is more customizable, but also more strict when it comes to syntax.
" 
" 'smartindent' and 'cindent' might interfere with file type based indentation, and should never be used in conjunction with it.
" 
" When it comes to C and C++, file type based indentations automatically sets 'cindent', and for that reason, there is no need to set 'cindent' manually for such files. In these cases, the 'cinwords', 'cinkeys' and 'cinoptions' options still apply.
" 
" Generally, 'smartindent' or 'cindent' should only be set manually if you're not satisfied with how file type based indentation works.（仅当你对基于文件类型的缩进不满意时，才需要设置'smartindent' or 'cindent'）
" 
"  参照【2】的介绍，
" 
" smartindent is an old script that was meant, when it was written, to be a "smart" complement to autoindent. Since then, most languages have either specific indentation functions or use cindent with specific options.
" 
" Generally, smartindent shouldn't be used at all.
" 
" The following lines are usually enough to deal with indentation（通常，如下设置便足够了）:
" 
" set autoindent
" filetype plugin indent on 
 
 
"------------------------------------------------------------------------------
" 6. vim粘贴代码格式变乱
" 
" 有时候从编辑器里面复制粘贴代码到vim中，代码格式会完全乱套。其原因是vim开启了smartindent(智能缩减)或autoindent(自动对齐)模式。为了保持代码的格式，在粘贴前可以先停止上面的两种模式，在Normal模式下的命令为【1】：
" 
" :set nosmartindent
" :set noautoindent
" 
" 为了一个粘贴搞出这么多事来，确实是麻烦。不过还有一个更加简单的方法，用命令开始粘贴模式，即：
" 
" （1）开启
" :set paste
" （2）按i进入插入模式，然后执行粘贴操作
" 为什么要先进入插入模式再粘贴呢？因为你所要粘贴的内容如果含有字符i的话，在Normal模式下，字符i会被Vim看做是插入命令，i字符前面的内容会被丢失（比如复制 #include <stdio.h>,复制的结果为 nclude <stdio.h>）。
" （3）关闭
" :set nopaste 或 :set paste!
" 
" 由于粘贴模式和上面的smartindent、autoindent模式是互斥的，而smartindent、autoindent是不可少的，所以粘贴完后使用上面的两条命令之一来关闭粘贴模式。
" 
"  
" 
" 另外还可以通过绑定自定义快捷键的方式来快速切换，例如将下属配置加入到.vimrc中
" 
" 方式1：
" set pastetoggle=<F4>
" 
" 方式2：
" :map <F8> :set paste
" :map <F9> :set nopaste
" 
" 注意：方式1在阅读和编辑模式下都可以使用，对粘贴模式开启和关闭进行切换；方式2是在阅读模式下使用，按下相应的快捷键就相当于执行后面定义的命令。



"------------------------------------------------------------------------------
" 当我谈vim映射时，我谈些什么
" 
" 这里说到的映射功能，指的是编辑器会捕获用户的输入，并且按照事先的设置来执行某些动作。
" 基础
" 
" 在vim里面自定义一个映射，格式如下：
" 
" maptype key action
" 
" 如：
" 
" inoremap jk <c-[> " 在insert模式下映射jk为Ctrl+[，也即进入normal模式
" 
" maptype表示映射的类型，分为两大类，带nore的和不带nore的（具体意义稍后再谈）……每一类中，根据映射的可用范围再分成若干类，具体类型通过:help map-overview可以查到。这里列举下重要的几类：
" 
"     map: 在所有模式下可用的映射
"     vmap：在visual和select模式下可用的映射
"     nmap：在normal模式下可用的映射
"     imap：在insert模式下可用的映射
"     omap：用于motion的一部分的映射。比如vw就是visual模式下选中一个词，可以用omap定义类似于w这样的动作操作符。
"     cmap：用于在命令行下（输入:或/之类后）可用的映射
" 
" key表示映射的键。什么样的键可以被映射呢？基本上你在键盘上能看到的键都能被映射（实际情况并不如此理想，等会解释）。如果你想映射特殊的键，比如，可不能就直接打个上去，而要使用<space>来表示。各种特殊符号具体的表示方式见:help key-notation。注意不仅能映射单个键，还能映射一组键，比如noremap afhaso; 脸滚键盘。
" 
" action就是映射出来的动作。可以是一串字符串，或者调用一个函数，还可以是调用一个vim命令。这个就要看大家的想象力了。
" 进阶
" 
" 从这里开始就要举出更多映射的例子啦。
" 
"     Notice! 不要说“为什么要这样映射，XX键本来有YY功能，这样做不对”之类的话，毕竟这个是关乎personal taste的事情。这里提醒下，在映射一组键之前，先看下这个键是不是已经有默认的功能了，然后看下这组键是否被映射了，再来决定要不要映射它。否则等到已经习惯后，一旦想要改，也没那么方便了。
" 
"     通过:help命令查看某组键是否有系统默认功能。
"     通过:map命令可以显示当前键映射的情况。
" 
" noremap VS map
" 
" noremap表示不允许映射的结果参与其他的映射规则的匹配。而map会使得映射的结果可以继续匹配其他的映射规则。
" 
" 举个例子：
" 
" nnoremap ; :
" nnoremap : ;
" 
" 这里把;和:两个符号互换了，因为在normal模式下，:用到的频率比;高。假如这里用到的是nmap呢？那会导致vim卡上一段时间，直到你按下Ctrl+c或者抛出个错误。所以基本上都是用noremap作为映射。
" 
" 当然map也有用武之地，比如当你需要映射的结果来触发另一个映射时，就用得上map了。
" cnoremap Or command
" 
" cnoremap会在命令行里起作用。
" 试一下输入：:cnoremap w!! w !sudo tee >/dev/null %
" 然后敲:进入命令行，快速地敲出w!!，你会发现它展开成为w !sudo tee >/dev/null %。这就是cnoremap的效果了。
" 
" 用cnoremap可以大大缩短常用命令的输入时间。举个例子，你可以使用cnoremap UE UltiSnipsEdit来代替敲入整个命令（或者多次敲打tab键）。不过前提是你的手速要足够快……
" 
" 其实为什么不用command呢（现在:help command看看）。你可以用command命令给某个命令做别名，这样就不用依赖足够快的手速了。
" can map and can't map
" 
" 前面说过，实际上不是所有的键可以作为vim映射的键。这是因为要想触发vim映射，你要让vim捕获到某一组键才行。但是有些键不会被传递给vim，可能半途就被其他程序偷吃掉了。这种情况在终端vim下特别明显。因为终端会占用一些快捷键，而且有些特殊的键值，比如shift+tab，即使终端它自己不用，也不给vim使用（好过分喔）。所以到底某个键能不能拿来做映射，还是得试了才知道。
" 脑洞大开
" 
" 在这一部分，我来分享些自己觉得有用的映射，但求抛砖引玉。
" 
" " 切换鼠标模式和无鼠标模式。方便复制
" function! ToggleMouse()
"     if &mouse ==# 'a'
"         set mouse=
"         set norelativenumber
"         set nonumber
"         echo 'no mouse mode'
"     else
"         set mouse=a
"         set number
"         set relativenumber
"         echo 'mouse mode'
"     endif
" endfunction
" 
" noremap <F2> :call ToggleMouse()<CR>
" 
" " 在安装了ag.vim插件后，查询光标下的内容
" nnoremap <leader>sc :Ag! <cWORD>
" 
" " 在新的tab里编辑当前目录下的其他文件
" nnoremap <C-down> :tabedit <c-r>=expand("%:p:h")<cr>/
" 
" " 快速开始一个全局替换
" nnoremap <leader>s :%s///gc<left><left><left> 
" 
" " 编辑shell文件时，调用man命令查看文档
" au FileType sh nnoremap <leader>m  :!man <cWORD><cr>



"------------------------------------------------------------------------------
" 4.9 内容替换
" 
" 有个名为 iFoo 的全局变量，被工程中 16 个文件引用过，由于你岳母觉得匈牙利命名法严重、异常、绝对以及十分万恶，为讨岳母欢心，不得不将该变量更名为 foo，怎么办？依次打开每个文件，逐一查找后替换？vim 有强大的内容替换命令：
" 
" :[range]s/{pattern}/{string}/[flags]
" 
" 在进行内容替换操作时，我关注几个因素：如何指定替换文件范围、是否整词匹配、是否逐一确认后再替换。
" 
" 如何指定替换文件范围？
" 
"     如果在当前文件内替换，[range] 不用指定，默认就在当前文件内；
" 
"     如果在当前选中区域，[range] 也不用指定，在你键入替换命令时，vim 自动将生成如下命令：
" 
" :'<,'>s/{pattern}/{string}/[flags]
" 
"     你也可以指定行范围，如，第三行到第五行：
" 
" :3,5s/{pattern}/{string}/[flags]
" 
"     如果对打开文件进行替换，你需要先通过 :bufdo 命令显式告知 vim 范围，再执行替换；
" 
"     如果对工程内所有文件进行替换，先 :args **/.cpp */*.h 告知 vim 范围，再执行替换；
" 
" 是否整词匹配？{pattern} 用于指定匹配模式。如果需要整词匹配，则该字段应由 < 和 > 修饰待替换字符串（如，<iFoo>）；无须整词匹配则不用修饰，直接给定该字符串即可；
" 
" 是否逐一确认后再替换？[flags] 可用于指定是否需要确认。若无须确认，该字段设定为 ge 即可；有时不见得所有匹配的字符串都需替换，若在每次替换前进行确认，该字段设定为 gec 即可。
" 
" 是否整词匹配和是否确认两个条件叠加就有 4 种组合：非整词且不确认、非整词且确认、整词且不确认、整词且确认，每次手工输入这些命令真是麻烦；我把这些组合封装到一个函数中，如下 Replace() 所示：
" 
" " 替换函数。参数说明：
" " confirm：是否替换前逐一确认
" " wholeword：是否整词匹配
" " replace：被替换字符串
" function! Replace(confirm, wholeword, replace)
"     wa
"     let flag = ''
"     if a:confirm
"         let flag .= 'gec'
"     else
"         let flag .= 'ge'
"     endif
"     let search = ''
"     if a:wholeword
"         let search .= '\<' . escape(expand('<cword>'), '/\.*$^~[') . '\>'
"     else
"         let search .= expand('<cword>')
"     endif
"     let replace = escape(a:replace, '/\&~')
"     execute 'argdo %s/' . search . '/' . replace . '/' . flag . '| update'
" endfunction
" 
" 为最大程度减少手工输入，Replace() 还能自动提取待替换字符串（只要把光标移至待替换字符串上），同时，替换完成后自动为你保存更改的文件。现在要做的就是赋予 confirm、wholeword 不同实参实现 4 种组合，再绑定 4 个快捷键即可。如下：
" 
" " 不确认、非整词
" nnoremap <Leader>R :call Replace(0, 0, input('Replace '.expand('<cword>').' with: '))<CR>
" " 不确认、整词
" nnoremap <Leader>rw :call Replace(0, 1, input('Replace '.expand('<cword>').' with: '))<CR>
" " 确认、非整词
" nnoremap <Leader>rc :call Replace(1, 0, input('Replace '.expand('<cword>').' with: '))<CR>
" " 确认、整词
" nnoremap <Leader>rcw :call Replace(1, 1, input('Replace '.expand('<cword>').' with: '))<CR>
" nnoremap <Leader>rwc :call Replace(1, 1, input('Replace '.expand('<cword>').' with: '))<CR>
" 
" 我平时用的最多的无须确认但整词匹配的替换模式，即 <leader>rw。
" 
" 请将完整配置信息添加进 .vimrc 中：
" 
" " 替换函数。参数说明：
" " confirm：是否替换前逐一确认
" " wholeword：是否整词匹配
" " replace：被替换字符串
" function! Replace(confirm, wholeword, replace)
"     wa
"     let flag = ''
"     if a:confirm
"         let flag .= 'gec'
"     else
"         let flag .= 'ge'
"     endif
"     let search = ''
"     if a:wholeword
"         let search .= '\<' . escape(expand('<cword>'), '/\.*$^~[') . '\>'
"     else
"         let search .= expand('<cword>')
"     endif
"     let replace = escape(a:replace, '/\&~')
"     execute 'argdo %s/' . search . '/' . replace . '/' . flag . '| update'
" endfunction
" " 不确认、非整词
" nnoremap <Leader>R :call Replace(0, 0, input('Replace '.expand('<cword>').' with: '))<CR>
" " 不确认、整词
" nnoremap <Leader>rw :call Replace(0, 1, input('Replace '.expand('<cword>').' with: '))<CR>
" " 确认、非整词
" nnoremap <Leader>rc :call Replace(1, 0, input('Replace '.expand('<cword>').' with: '))<CR>
" " 确认、整词
" nnoremap <Leader>rcw :call Replace(1, 1, input('Replace '.expand('<cword>').' with: '))<CR>
" nnoremap <Leader>rwc :call Replace(1, 1, input('Replace '.expand('<cword>').' with: '))<CR>
" 
" 比如，我将工程的所有 *.cpp 和 *.h 中的关键字 MyClassA 按不确认且整词匹配模式替换成 MyClass，所以注释中的关键字不会被替换掉。如下所示：
"



"5.2 模板补全

"开发时，我经常要输入相同的代码片断，比如 if-else、switch 语句，如果每个字符全由手工键入，我可吃不了这个苦，我想要简单的键入就能自动帮我完成代码模板的输入，并且光标停留在需要我编辑的位置，比如键入 if，vim 自动完成

"if (/* condition */) {
    "TODO
"}

"而且帮我选中 /* condition */ 部分，不会影响编码连续性 —— UltiSnips（https://github.com/SirVer/ultisnips ），我的选择。

"在进行模板补全时，你是先键入模板名（如，if），接着键入补全快捷键（默认 <tab>），然后 UltiSnips 根据你键入的模板名在代码模板文件中搜索匹配的“模板名-模板”，找到对应模板后，将模板在光标当前位置展开。

"UltiSnips 有一套自己的代码模板语法规则，类似：

"snippet if "if statement" i
"if (${1:/* condition */}) { 
    "${2:TODO} 
"} 
"endsnippet

"其中，snippet 和 endsnippet 用于表示模板的开始和结束；if 是模板名；"if statement" 是模板描述，你可以把多个模板的模板名定义成一样（如，if () {} 和 if () {} else {} 两模板都定义成相同模板名 if），在模板描述中加以区分（如，分别对应 "if statement" 和 "if-else statement"），这样，在 YCM（重量级智能补全插件） 的补全列表中可以根据模板描述区分选项不同模板；i 是模板控制参数，用于控制模板补全行为，具体参见“快速编辑结对符”一节；${1}、${2} 是 <tab> 跳转的先后顺序。

"新版 UltiSnips 并未自带预定义的代码模板，你可以从 https://github.com/honza/vim-snippets 获取各类语言丰富的代码模板，也可以重新写一套符合自己编码风格的模板。无论哪种方式，你需要在 .vimrc 中设定该模板所在目录名，以便 UltiSnips 寻找到。比如，我自定义的代码模板文件 cpp.snippets，路径为 ~/.vim/bundle/ultisnips/mysnippets/cpp.snippets，对应设置如下： let g:UltiSnipsSnippetDirectories=["mysnippets"] 其中，目录名切勿取为 snippets，这是 UltiSnips 内部保留关键字；另外，目录一定要是 ~/.vim/bundle/ 下的子目录，也就是 vim 的运行时目录。

"完整 cpp.snippets 内容如下：

"#================================= 
"#预处理 
"#================================= 
"# #include "..." 
"snippet INC 
"#include "${1:TODO}"${2} 
"endsnippet 
"# #include <...> 
"snippet inc 
"#include <${1:TODO}>${2} 
"endsnippet 
"#================================= 
"#结构语句 
"#================================= 
"# if 
"snippet if 
"if (${1:/* condition */}) { 
    "${2:TODO} 
"} 
"endsnippet 
"# else if 
"snippet ei 
"else if (${1:/* condition */}) { 
    "${2:TODO} 
"} 
"endsnippet 
"# else 
"snippet el 
"else { 
    "${1:TODO} 
"} 
"endsnippet 
"# return 
"snippet re 
"return(${1:/* condition */}); 
"endsnippet 
"# Do While Loop 
"snippet do 
"do { 
    "${2:TODO} 
"} while (${1:/* condition */}); 
"endsnippet 
"# While Loop 
"snippet wh 
"while (${1:/* condition */}) { 
    "${2:TODO} 
"} 
"endsnippet 
"# switch 
"snippet sw 
"switch (${1:/* condition */}) { 
    "case ${2:c}: { 
    "} 
    "break; 

    "default: { 
    "} 
    "break; 
"} 
"endsnippet 
"# 通过迭代器遍历容器（可读写） 
"snippet for 
"for (auto ${2:iter} = ${1:c}.begin(); ${3:$2} != $1.end(); ${4:++iter}) {
    "${5:TODO} 
"} 
"endsnippet 
"# 通过迭代器遍历容器（只读） 
"snippet cfor 
"for (auto ${2:citer} = ${1:c}.cbegin(); ${3:$2} != $1.cend(); ${4:++citer}) { 
    "${5:TODO} 
"} 
"endsnippet 
"# 通过下标遍历容器 
"snippet For 
"for (auto ${2:i} = 0; $2 != ${1}.size(); ${3:++}$2) { 
    "${4:TODO} 
"} 
"endsnippet 
"# C++11风格for循环遍历（可读写） 
"snippet F 
"for (auto& e : ${1:c}) { 
"} 
"endsnippet 
"# C++11风格for循环遍历（只读） 
"snippet CF 
"for (const auto& e : ${1:c}) { 
"} 
"endsnippet 
"# For Loop 
"snippet FOR 
"for (unsigned ${2:i} = 0; $2 < ${1:count}; ${3:++}$2) { 
    "${4:TODO} 
"} 
"endsnippet 
"# try-catch 
"snippet try 
"try { 
"} catch (${1:/* condition */}) { 
"} 
"endsnippet 
"snippet ca 
"catch (${1:/* condition */}) { 
"} 
"endsnippet 
"snippet throw 
"th (${1:/* condition */}); 
"endsnippet 
"#================================= 
"#容器 
"#================================= 
"# std::vector 
"snippet vec 
"vector<${1:char}>   v${2}; 
"endsnippet 
"# std::list 
"snippet lst 
"list<${1:char}> l${2}; 
"endsnippet 
"# std::set 
"snippet set 
"set<${1:key}>   s${2}; 
"endsnippet 
"# std::map 
"snippet map 
"map<${1:key}, ${2:value}>   m${3}; 
"endsnippet 
"#================================= 
"#语言扩展 
"#================================= 
"# Class 
"snippet cl 
"class ${1:`Filename('$1_t', 'name')`} 
"{ 
    "public: 
        "$1 (); 
        "virtual ~$1 (); 

    "private: 
"}; 
"endsnippet 
"#================================= 
"#结对符 
"#================================= 
 "# 括号 bracket 
"snippet b "bracket" i 
"(${1})${2} 
"endsnippet 
"# 方括号 square bracket，设定为 st 而非 sb，避免与 b 冲突
"snippet st "square bracket" i 
"[${1}]${2} 
"endsnippet 
"# 大括号 brace 
"snippet br "brace" i 
"{ 
    "${1} 
"}${2} 
"endsnippet 
"# 单引号 single quote，设定为 se 而非 sq，避免与 q 冲突
"snippet se "single quote" I
"'${1}'${2}
"endsnippet
"# 双引号 quote
"snippet q "quote" I
""${1}"${2}
"endsnippet
"# 指针符号 arrow 
"snippet ar "arrow" i 
"->${1} 
"endsnippet 
"# dot 
"snippet d "dot" i 
".${1} 
"endsnippet 
"# 作用域 scope 
"snippet s "scope" i 
"::${1} 
"endsnippet

"默认情况下，UltiSnips 模板补全快捷键是 <tab>，与后面介绍的 YCM 快捷键有冲突，所有须在 .vimrc 中重新设定：

"" UltiSnips 的 tab 键与 YCM 冲突，重新设定
"let g:UltiSnipsExpandTrigger="<leader><tab>"
"let g:UltiSnipsJumpForwardTrigger="<leader><tab>"
"let g:UltiSnipsJumpBackwardTrigger="<leader><s-tab>"





"6.3 环境恢复*

"vim 的编辑环境保存与恢复是我一直想要的功能，我希望恢复：已打开文件、光标位置、undo/redo、书签、子窗口、窗口大小、窗口位置、命令历史、buffer 列表、代码折叠。vim 文档说借助 viminfo（恢复书签） 和 session（恢复除书签外的其他项）特性很可以实现这个功能。请确保你的 vim 支持 +mksession 和 +viminfo 特性：

"vim --version | grep mksession
"vim --version | grep viminfo

"如果编译 vim 时添加了 --with-features=huge 选项那就没问题。

"一般说来，保存/恢复环境步骤如下。

"第一步，保存所有文档：

":wa

"第二步，借助 viminfo 和 session 保存当前环境：

":mksession! my.vim
":wviminfo! my.viminfo

"第三步，退出 vim：

":qa

"第四步，恢复环境，进入 vim 后执行：

":source my.vim
":rviminfo my.viminfo

"具体能保存哪些项，可由 sessionoptions 指定，另外，前面几步可以设定快捷键，在 .vimrc 中增加：

"" 设置环境保存项
"set sessionoptions="blank,buffers,globals,localoptions,tabpages,sesdir,folds,help,options,resize,winpos,winsize"
"" 保存 undo 历史
"set undodir=~/.undo_history/
"set undofile
"" 保存快捷键
"map <leader>ss :mksession! my.vim<cr> :wviminfo! my.viminfo<cr>
"" 恢复快捷键
"map <leader>rs :source my.vim<cr> :rviminfo my.viminfo<cr>

"这样，简化第二步、第四步操作。另外，sessionoptions 无法覆盖 undo 历史，所以，必须通过开启 undofile 进行单独设置，一旦开启，每次写文件时自动强制保存 undo 历史，下次加载在文件时自动强制恢复所有 undo 历史，不在由 :mksession/:wviminfo 和 :source/:rviminfo 控制。

"按此操作，并不能像 vim 文档中描述的那样能保存所有环境，比如，书签、代码折叠、命令历史都无法恢复。这和我预期存在较大差距，暂且用用吧，找个时间在深入研究！


nmap <C-F>f <Plug>CtrlSFPrompt<CR>

nmap <C-F>c <Plug>CtrlSFCwordExec
nmap <C-F>C <Plug>CtrlSFCwordPath
nmap <C-F>p <Plug>CtrlSFPwordExec
nmap <C-F>P <Plug>CtrlSFPwordPath
vmap <C-F>v <Plug>CtrlSFVwordExec
vmap <C-F>V <Plug>CtrlSFVwordPath

let g:ycm_always_populate_location_list = 1

" airline设置
set t_Co=256
set laststatus=2
" 开启tabline
let g:airline#extensions#tabline#enabled = 1
" tabline中当前buffer两端的分隔字符
let g:airline#extensions#tabline#left_sep = ' '
" tabline中未激活buffer两端的分隔字符
let g:airline#extensions#tabline#left_alt_sep = '|'
" tabline中buffer显示编号
let g:airline#extensions#tabline#buffer_nr_show = 1
let g:airline_theme='molokai'
"let g:airline_theme='durant'

" 映射切换buffer的键位
nnoremap [b :bp<CR>
nnoremap ]b :bn<CR>

"k-vim 一个vim插件集成,里面有些插件还是相当不错，有空研究研究


" 到行首行尾
noremap H ^
noremap L $
" t/T增加空行
nmap t o<ESC>
nmap T O<ESC>

let g:rainbow_active = 1
