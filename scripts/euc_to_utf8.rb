#!/usr/bin/ruby -w
# simple script for turning the euc file into unicode 8
require 'iconv'

begin
  utf8file = File.open("edict_utf8.txt", "w")
  File.open("edict").each do |line|
    utf8file << Iconv.iconv("utf-8","euc-jp",line)
  end
  utf8file.close
end
