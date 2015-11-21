set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

"" The following are examples of different formats supported.
"" Keep Plugin commands between vundle#begin/end.
"" plugin on GitHub repo
"Plugin 'tpope/vim-fugitive'
"" plugin from http://vim-scripts.org/vim/scripts.html
"Plugin 'L9'
"" Git plugin not hosted on GitHub
"Plugin 'git://git.wincent.com/command-t.git'
"" git repos on your local machine (i.e. when working on your own plugin)
"Plugin 'file:///home/gmarik/path/to/plugin'
"" The sparkup vim script is in a subdirectory of this repo called vim.
"" Pass the path to set the runtimepath properly.
"Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
"" Avoid a name conflict with L9
"Plugin 'user/L9', {'name': 'newL9'}
Bundle 'Valloric/YouCompleteMe'

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





let g:ycm_global_ycm_extra_conf = '~/.vim/data/ycm/.ycm_extra_conf.py'
" 不显示开启vim时检查ycm_extra_conf文件的信息  
let g:ycm_confirm_extra_conf=0
" 开启基于tag的补全，可以在这之后添加需要的标签路径  
let g:ycm_collect_identifiers_from_tags_files=1
"注释和字符串中的文字也会被收入补全
let g:ycm_collect_identifiers_from_comments_and_strings = 0
" 输入第2个字符开始补全
let g:ycm_min_num_of_chars_for_completion=2
" 禁止缓存匹配项,每次都重新生成匹配项
let g:ycm_cache_omnifunc=0
" 开启语义补全
"let g:ycm_seed_identifiers_with_syntax=1	
"在注释输入中也能补全
let g:ycm_complete_in_comments = 1
"在字符串输入中也能补全
let g:ycm_complete_in_strings = 1
" 设置在下面几种格式的文件上屏蔽ycm
let g:ycm_filetype_blacklist = {
      \ 'tagbar' : 1,
      \ 'nerdtree' : 1,
      \}
" 令Preview window在补全后自动关闭
au CompleteDone * pclose

nnoremap <F5> :YcmForceCompileAndDiagnostics<CR>    
nnoremap <leader>jf :YcmCompleter GoToDeclaration<CR>
nnoremap <leader>jd :YcmCompleter GoToDefinitionElseDeclaration<CR>
" 开启语法实时检测功能
"let g:ycm_show_diagnostics_ui = 1
"youcompleteme  默认tab  s-tab 和 ultisnips 冲突
"let g:ycm_key_list_select_completion = ['<Down>']
"let g:ycm_key_list_previous_completion = ['<Up>']
" 修改对C函数的补全快捷键，默认是CTRL + space，修改为ALT + ;
let g:ycm_key_invoke_completion = '<S-space>'
let g:ycm_enable_diagnostic_highlighting = 1


"
" Options for syntastic
"
execute pathogen#infect()
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0
let g:syntastic_cpp_include_dirs = ['/usr/include/qt4', '/usr/include/qt4/Qt/']


"
" Options for Winmanager
"
let g:winManagerWindowLayout = "TagList|FileExplorer"
"设置winmanager的宽度，默认为25
let g:winManagerWidth = 25
"定义打开关闭winmanager快捷键为wm
nmap wm :WMToggle<cr>
"在进入vim时自动打开winmanager
" Options for Winmanager
"
let g:winManagerWindowLayout = "TagList|FileExplorer"
"设置winmanager的宽度，默认为25
let g:winManagerWidth = 25
"定义打开关闭winmanager快捷键为wm
nmap wm :WMToggle<cr>
"在进入vim时自动打开winmanager


"
" Options for Taglist
"
let Tlist_Show_One_File=1   "只显示当前文件的tags
let Tlist_WinWidth=20       "设置taglist宽度
let Tlist_Exit_OnlyWindow=1 "Taglist 窗口是最后一个窗口
let Tlist_Use_Left_Window=1 "左侧显示taglist窗口
let Tlist_Auto_OPen=1


" 
" Options for cscope
"自动载入cscope文件
"只能在 cscope.out所在目录下使用vim才能正确载入
if filereadable("cscope.out")
	cs add cscope.out
elseif $CSCOPE_DB != ""
	cs add $CSCOPE_DB
endif

"CSCOPE 快捷键
"s：查找C代码符号
"g：查找本定义
"d：查找本函数调用的函数
"c：查找调用本函数的函数
"t：查找本字符串
"e：查找本egrep模式
"f：查找本文件
"i：查找包含本文件的文件
nmap <C-@>s : cs find s <C-R>=expand("<cword>")<CR><CR>	
nmap <C-@>g : cs find g <C-R>=expand("<cword>")<CR><CR>
nmap <C-@>c :cs find c <C-R>=expand("<cword>")<CR><CR>
nmap <C-@>t :cs find t <C-R>=expand("<cword>")<CR><CR>
nmap <C-@>e :cs find e <C-R>=expand("<cword>")<CR><CR>
nmap <C-@>f :cs find f <C-R>=expand("<cword>")<CR><CR>
nmap <C-@>i :cs find i ^<C-R>=expand("<cword>")<CR>$<CR>
nmap <C-@>d :cs find d <C-R>=expand("<cword>")<CR><CR>

nmap <C-@>v : cs find g  


"
" User defined options 
"
"括号补全功能
set showmatch
""inoremap ( ()<ESC>i
""inoremap [ []<ESC>i
""inoremap { {}<ESC>i<CR><CR><ESC>ka<tab>
""inoremap " ""<ESC>i
""inoremap ' ''<ESC>i
""inoremap #inc #include <><ESC>i
"nunmap <C-i>

set nu
source ~/ctags.vim
call AutoLoadCtags()
nmap <F7> : call RefreshCtags()<ESC>

" 缩进设置
set tabstop=4
set softtabstop=4
set shiftwidth=4

"Tab 表示切换至下一个窗口
nmap <tab> <ESC>:tabnext<CR>
nmap `	<ESC>:tabprev<CR>

"设置配色方案
colorscheme lucius 
LuciusBlack


"Pyclewn  GDB debug
map <F2> :exe "Cprint " . expand("<cword>") <CR>
:command -nargs=1 Debug :call GDB("<args>")<CR>
function! GDB(fname)
	:Pyclewn
	:Cinferiortty
	:exe "Cfile " a:fname
	:Cmapkeys
	:e main.c
endf
