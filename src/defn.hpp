class Something@\tikzmark{decl_class}@ {
  void declared() const noexcept;@\tikzmark{decl_decl}@

  @\tikzmark{decl_defn}@void defined() {
    // Etc.
  }
};

void Something::declared() const noexcept {}@\tikzmark{decl_decl_defn}@

int note_the_parameters(int i, float f) {
  return i + f;
}

@\tikzmark{decl_func_defn}@int note_the_parameters(int i) {
  return i;
}