#!/usr/bin/env ruby

tokens = File.open(ARGV[0]).read().split
tokens = tokens.select { |t| !t.empty? }.sort.uniq

File.open(File.dirname(__FILE__) + "/" + ARGV[1] + ".g4", "w+") do |f|
    f.puts("// This file was automatically generated by 'scritps/generate_tokens.rb'")
    f.puts("grammar " + ARGV[1] + ";")
    f.puts
    tokens.select { |t| !t.empty? }.sort.uniq.each do |t|
        f.puts "%s: %s;" % [t, t.split(//).map {
            |c| c == "_" ? "'_'" : (c =~ /[[:digit:]]/ ? "'" + c + "'" : c)
        }.join(' ')]
    end
    f.puts
    ('A'..'Z').map do |letter|
        f.puts("fragment %s: [%s%s];" % [letter, letter, letter.downcase]);
    end
    f.puts
    f.puts("ID: NON_DIGIT (F_DIGIT | NON_DIGIT)*;");
    f.puts("FLOAT_NUMBER: (INT_NUMBER)? F_PERIOD INT_NUMBER E (F_PLUS | F_MINUS) INT_NUMBER;");
    f.puts("INT_NUMBER: F_DIGIT+;");
    f.puts("SQUOTED_STRING: F_SQUOTE (('\\\\' . ) | '\\'\\'' | ~('\\\\' | '\\''))* F_SQUOTE;");
    f.puts("DQUOTED_STRING: F_DQUOTE (('\\\\' .) | '\"\"' | ~('\\\\' | '\"'))+ F_DQUOTE;");
    f.puts("BQUOTED_STRING: F_BQUOTE (('``') | ~('`'))+ F_BQUOTE;");
    f.puts("NON_DIGIT: F_ALPHA | F_DOLLAR | F_ATSIGN | F_USCORE;");
    f.puts("BLOCK_COMMENT:'/*' (.)*? '*/' -> skip;");
    f.puts("LINE_COMMENT: ('#' | '--') (~'\\n')* ('\\n' | EOF) -> skip;");
    f.puts("WHITE_SPACE: F_WSPACE+ -> channel(HIDDEN);");
    f.puts
    f.puts("fragment F_DIGIT: [0-9];")
    f.puts("fragment F_ALPHA: [a-zA-Z\\u0080-\\uFFFF];")
    f.puts("fragment F_WSPACE: [ \\t\\n\\r];")
    f.puts("fragment F_SQUOTE: '\\'';")
    f.puts("fragment F_DQUOTE: '\"';")
    f.puts("fragment F_BQUOTE: '`';")
    f.puts("fragment F_BSLASH: '\\\\';")
    f.puts("fragment F_DOLLAR: '$';")
    f.puts("fragment F_ATSIGN: '@';")
    f.puts("fragment F_USCORE: '_';")
    f.puts("fragment F_PLUS: '+';")
    f.puts("fragment F_MINUS: '-';")
    f.puts("fragment F_PERIOD: '.';")
    f.puts
    f.puts("LPAREN: '(';")
    f.puts("RPAREN: ')';")
    f.puts("PERIOD: '.';")
    f.puts("COMMA: ',';")
    f.puts("COLON: ':';")
    f.puts("SEMI: ';';")
    f.puts("EQUAL: '=';")
end
