function LaTeXify()
%LaTeXify
%
% Copyright (c) 2023 Jeremy W. Hopwood. All rights reserved.
%
% This function ensures all default interpreters are set to LaTeX
%

list_factory = fieldnames(get(groot,'factory'));
index_interpreter = find(contains(list_factory,'Interpreter'));
for i = 1:length(index_interpreter)
    default_name = strrep(list_factory{index_interpreter(i)},'factory','default');
    set(groot, default_name,'latex');
end

end

