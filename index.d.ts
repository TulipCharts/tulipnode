declare module "tulind" {
  export type Indicator = {
    name: IndicatorIndentifier;
    full_name: string;
    type: IndicatorType;
    inputs: number;
    options: number;
    outputs: number;
    input_names: string[];
    option_names: string[];
    output_names: string[];

    /**
     * Given these options, the output arrays will be
     * this much shorter than the input array.
     */
    start: (options: number[]) => number;

    /**
     * The indicator function.
     */
    indicator: (
      inputs: number[][],
      options: number[],
      cb: (err: Error | undefined, results: number[][]) => void
    ) => void;
  };

  export type IndicatorType =
    | "overlay"
    | "indicator"
    | "math"
    | "simple"
    | "comparative";

  export type IndicatorIndentifier =
    /** overlay */
    | "avgprice"
    | "bbands"
    | "dema"
    | "ema"
    | "hma"
    | "kama"
    | "linreg"
    | "medprice"
    | "psar"
    | "sma"
    | "tema"
    | "trima"
    | "tsf"
    | "typprice"
    | "vidya"
    | "vwma"
    | "wcprice"
    | "wilders"
    | "wma"
    | "zlema"
    /** indicator */
    | "ad"
    | "adosc"
    | "adx"
    | "adxr"
    | "ao"
    | "apo"
    | "aroon"
    | "aroonosc"
    | "atr"
    | "bop"
    | "cci"
    | "cmo"
    | "cvi"
    | "cmo"
    | "cvi"
    | "di"
    | "dm"
    | "dpo"
    | "dx"
    | "emv"
    | "fisher"
    | "fosc"
    | "kvo"
    | "linregintercept"
    | "linregslope"
    | "macd"
    | "marketfi"
    | "mass"
    | "mfi"
    | "mom"
    | "msw"
    | "natr"
    | "nvi"
    | "obv"
    | "ppo"
    | "pvi"
    | "qstick"
    | "roc"
    | "rocr"
    | "rsi"
    | "stoch"
    | "stochrsi"
    | "tr"
    | "trix"
    | "ultosc"
    | "vhf"
    | "volatility"
    | "vosc"
    | "wad"
    | "willr"
    /** math */
    | "crossany"
    | "crossover"
    | "decay"
    | "edecay"
    | "lag"
    | "max"
    | "md"
    | "min"
    | "stddev"
    | "stderr"
    | "sum"
    | "var"
    /** simple */
    | "abs"
    | "acos"
    | "add"
    | "add"
    | "asin"
    | "atan"
    | "ceil"
    | "cos"
    | "cosh"
    | "div"
    | "exp"
    | "floor"
    | "ln"
    | "log10"
    | "mul"
    | "round"
    | "sin"
    | "sinh"
    | "sqrt"
    | "sub"
    | "tan"
    | "tanh"
    | "todeg"
    | "torad"
    | "trunc";

  export const indicators: Record<IndicatorIndentifier, Indicator>;
  export const version: string;
}
