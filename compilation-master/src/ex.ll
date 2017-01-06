; ModuleID = 'ex.c'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-redhat-linux-gnu"

@w = common global double 0.000000e+00, align 8
@h = common global double 0.000000e+00, align 8
@angle = common global double 0.000000e+00, align 8
@angle_dir = common global i32 0, align 4
@N = common global i32 0, align 4

; Function Attrs: nounwind uwtable
define void @my_setup() #0 {
  store double 6.400000e+02, double* @w, align 8
  store double 4.800000e+02, double* @h, align 8
  store double 0.000000e+00, double* @angle, align 8
  store i32 0, i32* @angle_dir, align 4
  store i32 200, i32* @N, align 4
  %1 = load double* @w, align 8
  %2 = load double* @h, align 8
  %3 = call i32 (double, double, ...)* bitcast (i32 (...)* @createCanvas to i32 (double, double, ...)*)(double %1, double %2)
  ret void
}

declare i32 @createCanvas(...) #1

; Function Attrs: nounwind uwtable
define void @my_draw() #0 {
  %i = alloca i32, align 4
  %r = alloca double, align 8
  %1 = call i32 (i32, ...)* bitcast (i32 (...)* @background to i32 (i32, ...)*)(i32 0)
  store i32 0, i32* %i, align 4
  br label %2

; <label>:2                                       ; preds = %52, %0
  %3 = load i32* %i, align 4
  %4 = load i32* @N, align 4
  %5 = icmp slt i32 %3, %4
  br i1 %5, label %6, label %55

; <label>:6                                       ; preds = %2
  %7 = load i32* %i, align 4
  %8 = sitofp i32 %7 to double
  %9 = fmul double 2.550000e+02, %8
  %10 = load i32* @N, align 4
  %11 = sitofp i32 %10 to double
  %12 = fdiv double %9, %11
  %13 = call i32 (double, ...)* bitcast (i32 (...)* @fill to i32 (double, ...)*)(double %12)
  %14 = load i32* @N, align 4
  %15 = load i32* %i, align 4
  %16 = sub nsw i32 %14, %15
  %17 = sitofp i32 %16 to double
  %18 = fmul double 2.550000e+02, %17
  %19 = load i32* @N, align 4
  %20 = sitofp i32 %19 to double
  %21 = fdiv double %18, %20
  %22 = call i32 (double, ...)* bitcast (i32 (...)* @stroke to i32 (double, ...)*)(double %21)
  %23 = load i32* %i, align 4
  %24 = sitofp i32 %23 to double
  %25 = load double* @angle, align 8
  %26 = fadd double %24, %25
  store double %26, double* %r, align 8
  %27 = load double* @w, align 8
  %28 = fdiv double %27, 2.000000e+00
  %29 = load i32* %i, align 4
  %30 = sitofp i32 %29 to double
  %31 = load double* %r, align 8
  %32 = call double @sin(double %31) #3
  %33 = fmul double %30, %32
  %34 = fadd double %28, %33
  %35 = load double* @h, align 8
  %36 = fdiv double %35, 2.000000e+00
  %37 = load i32* %i, align 4
  %38 = sitofp i32 %37 to double
  %39 = load double* %r, align 8
  %40 = call double @cos(double %39) #3
  %41 = fmul double %38, %40
  %42 = fadd double %36, %41
  %43 = load i32* %i, align 4
  %44 = sitofp i32 %43 to double
  %45 = load double* @angle, align 8
  %46 = fmul double %44, %45
  %47 = load i32* %i, align 4
  %48 = sitofp i32 %47 to double
  %49 = load double* @angle, align 8
  %50 = fmul double %48, %49
  %51 = call i32 (double, double, double, double, ...)* bitcast (i32 (...)* @ellipse to i32 (double, double, double, double, ...)*)(double %34, double %42, double %46, double %50)
  br label %52

; <label>:52                                      ; preds = %6
  %53 = load i32* %i, align 4
  %54 = add nsw i32 %53, 1
  store i32 %54, i32* %i, align 4
  br label %2

; <label>:55                                      ; preds = %2
  %56 = load i32* @angle_dir, align 4
  %57 = icmp eq i32 %56, 0
  br i1 %57, label %58, label %65

; <label>:58                                      ; preds = %55
  %59 = load double* @angle, align 8
  %60 = fadd double %59, 1.000000e-02
  store double %60, double* @angle, align 8
  %61 = load double* @angle, align 8
  %62 = fcmp ogt double %61, 2.000000e+00
  br i1 %62, label %63, label %64

; <label>:63                                      ; preds = %58
  store i32 1, i32* @angle_dir, align 4
  br label %64

; <label>:64                                      ; preds = %63, %58
  br label %76

; <label>:65                                      ; preds = %55
  %66 = load i32* @angle_dir, align 4
  %67 = icmp eq i32 %66, 1
  br i1 %67, label %68, label %75

; <label>:68                                      ; preds = %65
  %69 = load double* @angle, align 8
  %70 = fsub double %69, 1.000000e-02
  store double %70, double* @angle, align 8
  %71 = load double* @angle, align 8
  %72 = fcmp olt double %71, -2.000000e+00
  br i1 %72, label %73, label %74

; <label>:73                                      ; preds = %68
  store i32 0, i32* @angle_dir, align 4
  br label %74

; <label>:74                                      ; preds = %73, %68
  br label %75

; <label>:75                                      ; preds = %74, %65
  br label %76

; <label>:76                                      ; preds = %75, %64
  ret void
}

declare i32 @background(...) #1

declare i32 @fill(...) #1

declare i32 @stroke(...) #1

declare i32 @ellipse(...) #1

; Function Attrs: nounwind
declare double @sin(double) #2

; Function Attrs: nounwind
declare double @cos(double) #2

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"clang version 3.4.2 (tags/RELEASE_34/dot2-final)"}
